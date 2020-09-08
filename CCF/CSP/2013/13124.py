mod = 1000000007

dp = [[0] * 6 for _ in range(1010)]

n = int(input())

for i in range(1, n + 1):
    dp[i][0] = 1
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % mod
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % mod
    dp[i][3] = (dp[i - 1][1] + dp[i - 1][3] * 2) % mod
    dp[i][4] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] * 2) % mod
    dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5] * 2) % mod

print(dp[n][5])
