n = int(input())
s = input()
if len(s) % n != 0:
    s += (' ' * (n - (len(s) % n)))
col = int(len(s) / n)
for i in range(n):
    for j in range(col, 0, -1):
        print(s[(j - 1) * n + i], end='')
    print()
