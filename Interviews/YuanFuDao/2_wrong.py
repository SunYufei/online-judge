t = int(input())

for _ in range(t):
    parts = input().split()
    op = []
    num = []

    valid = True
    for p in parts:
        if p[0] == '(':
            op.append(p[0])
            if len(p) > 1:
                if p[1] in '1234567890':
                    valid = False
                    break
                else:
                    op.append(p[1])
                    if len(p) > 2:
                        num.append(int(p[2:]))
        elif p[0] == ')':
            if len(op) < 2 or len(num) < 2:
                valid = False
                break
            else:
                o = op.pop()
                b = num.pop()
                a = num.pop()
                if o == '+':
                    num.append(a + b)
                elif o == '-':
                    num.append(a - b)
                elif o == '*':
                    num.append(a * b)
                op.pop()  # (
        elif p[0] in '+-*':
            op.append(p[0])
            if len(p) > 1:
                num.append(int(p[1:]))
        elif p[0] in '1234567890':
            if p[-1] == ')':
                num.append(int(p[:-1]))
                if len(op) < 2 or len(num) < 2:
                    valid = False
                    break
                else:
                    o = op.pop()
                    b = num.pop()
                    a = num.pop()
                    if o == '+':
                        num.append(a + b)
                    elif o == '-':
                        num.append(a - b)
                    elif o == '*':
                        num.append(a * b)
                    op.pop()  # (
            else:
                num.append(int(p))

    if not valid or len(op) != 0 or len(num) != 1:
        print('invalid')
    else:
        res = num[-1]
        print((res % 10000000 + 10000000) % 10000000)
