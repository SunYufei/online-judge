import operator
import sys


def convert_bool(func):
    def converted(*args, **kwargs):
        result = func(*args, **kwargs)
        return 'True' if result else 'False'
    return converted


class Lambda:
    def __init__(self, params, body, env, interpreter):
        self.params = params
        self.body = body
        self.env = env
        self.interpreter = interpreter

    def __str__(self):
        return f'Lambda{self.params} {self.body}'

    def __call__(self, *args):
        env = self.env.copy()
        for param, arg in zip(self.params, args):
            env[param] = arg
        return self.interpreter.evaluate(self.body, env)


class Interpreter:
    def __init__(self):
        self.env = {}
        self.env['False'] = 'False'
        self.env['True'] = 'True'
        self.env['+'] = operator.add
        self.env['-'] = operator.sub
        self.env['*'] = operator.mul
        self.env['/'] = lambda x, y: x // y if isinstance(
            x, int) and isinstance(y, int) else x / y
        self.env['eq?'] = convert_bool(operator.eq)

    def parse(self, line):
        tokens = line.replace('(', ' ( ').replace(')', ' ) ').split()
        stack = []
        stack.append([])
        for token in tokens:
            if token == '(':
                stack.append([])
            elif token == ')':
                top = tuple(stack.pop())
                stack[-1].append(top)
            else:
                atom = self.parse_atom(token)
                stack[-1].append(atom)
        return stack[-1][0]

    def parse_atom(self, token):
        try:
            atom = int(token)
        except ValueError:
            atom = token
        return atom

    def evaluate(self, expr, env=None):
        if env is None:
            env = self.env
        if not isinstance(expr, tuple):
            return env.get(expr, 'False') if isinstance(expr, str) else expr
        if not expr:    # empty list
            return expr
        action = expr[0]
        if isinstance(action, str):
            name = 'macro_'+action
            if hasattr(self, name):
                return getattr(self, name)(env, *expr[1:])
        # function application
        func = self.evaluate(action, env)
        args = [self.evaluate(arg, env) for arg in expr[1:]]
        return func(*args)

    def macro_define(self, env, name, value):
        value = self.evaluate(value, env)
        self.env[name] = value
        return 'define'

    def macro_lambda(self, env, params, body):
        return Lambda(params, body, env, self)

    def macro_cond(self, env, *clauses):
        for cond, body in clauses:
            test = self.evaluate(cond, env)
            if test is not 'False':
                return self.evaluate(body, env)
        return 'False'


if __name__ == "__main__":
    interpreter = Interpreter()
    for line in sys.stdin:
        expr = interpreter.parse(line.strip())
        result = interpreter.evaluate(expr)
        sys.stdout.write(f'{result}\n')
