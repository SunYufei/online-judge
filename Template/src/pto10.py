def p_to_ten(x: int, p: int) -> int:
    y, tmp = 0, 1
    while x != 0:
        y = y + (x % 10) * tmp
        x = x // 10
        tmp = tmp * p
    return y
