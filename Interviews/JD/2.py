n, p = map(int, input().split())

l = [(0, 0)]

for _ in range(n):
    a, b, c = map(int, input().split())
    t = 1
    while a - t > 0:
        a -= t
        l.append((t * b, t * c))
        t *= 2
    l.append((a * b, a * c))

dp = [0] * (p + 1)

for i in range(1, len(l)):
    for j in range(p, l[i][0] - 1, -1):
        dp[j] = max(dp[j], dp[j - l[i][0]] + l[i][1])

print(dp[p])
