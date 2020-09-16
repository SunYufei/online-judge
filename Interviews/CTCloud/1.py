n = int(input())

dp = [1] * n
a, b, c = 0, 0, 0

for i in range(1, n):
    n2, n3, n5 = dp[a] * 2, dp[b] * 3, dp[c] * 5
    dp[i] = min(n2, n3, n5)
    if dp[i] == n2:
        a += 1
    if dp[i] == n3:
        b += 1
    if dp[i] == n5:
        c += 1

print(dp[-1])
