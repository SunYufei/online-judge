from math import gcd

n, m = map(int, input().split())

y = []

for _ in range(m):
    y.append(int(input()))

f = (1 << m) - 1
ans = 0
gd = 0

for i in range(1, f + 1):
    count = 0
    for j in range(m):
        if i & (1 << j):
            count += 1
            if count == 1:
                gd = y[j]
            else:
                gd = gd * y[j] // gcd(y[j], gd)
    if count & 1:
        ans += (n // gd)
    else:
        ans -= (n // gd)

print(ans)
