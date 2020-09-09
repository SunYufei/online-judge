n, m = map(int, input().split())

ans = 0

dp = [0] * 40010
c = [0] * (n + 1)
v = [0] * (n + 1)

for i in range(1, n + 1):
    c[i], v[i] = map(int, input().split())
    if c[i] <= 0:
        ans += v[i]
        m -= c[i]
        c[i] = -c[i]
        v[i] = -v[i]

for i in range(1, n + 1):
    for j in range(m, c[i] - 1, -1):
        dp[j] = max(dp[j], dp[j - c[i]] + v[i])

for i in range(m + 1):
    dp[m] = max(dp[m], dp[i])

print(ans + dp[m])
