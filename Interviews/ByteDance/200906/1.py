n = int(input())

dp = [0] * (n + 10)

for i in range(4):
    dp[i] = i

for i in range(4, n + 1):
    dp[i] = dp[i - 1] + dp[i - 3]

print(dp[n], end='')