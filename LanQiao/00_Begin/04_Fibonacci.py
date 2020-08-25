n = int(input())
if n < 2:
    print(n)
else:
    p, c = 0, 1
    for i in range(2, n + 1):
        c = (p + c) % 10007
        p = c - p
    print(c)