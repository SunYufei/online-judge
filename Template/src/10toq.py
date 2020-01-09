def ten_to_q(y: int, q: int):
    z = []
    while y != 0:
        z.append(y % q)
        y = y // q
    print(''.join(map(str, reversed(z)))) if len(z) else print(0)
