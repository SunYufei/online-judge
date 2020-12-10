from random import randint


def get_calc_expression(min_, max_):
    max_count = (max_ - min_ - 1) * (max_ - min_) // 2
    res = set()
    # add
    while len(res) < min(5, max_count):
        a = randint(min_, max_ - min_)
        b = randint(min_, max_ - a)
        res.add((a, b))
    for a, b in res:
        print(f'{a}+{b}=()\t{a+b}')
    # minus
    res.clear()
    while len(res) < min(5, max_count):
        a = randint(min_ * 2, max_)
        b = randint(min_, a - min_)
        res.add((a, b))
    for a, b in res:
        print(f'{a}-{b}=()\t{a-b}')


get_calc_expression(2, 10)
print()
get_calc_expression(5, 20)
print()
get_calc_expression(2, 4)
print()
get_calc_expression(2, 3)
