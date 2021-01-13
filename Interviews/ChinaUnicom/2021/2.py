import math


def y(x):
    if x <= 0:
        return x * x
    elif 0 < x < 10:
        return math.sqrt(x)
    elif x >= 10:
        return x


x = int(input())
print(int(y(x)))
