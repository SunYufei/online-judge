import math

n = list(map(int, input().split()))
length = len(n)

dp = [math.inf] * length

for i in range(1, int(length / 2)):
    step = 1
    idx = i
    while idx < length:
        dp[idx] = min(dp[idx], step)
        idx = idx + n[idx]
        step += 1

if dp[length - 1] == math.inf:
    print(-1)
else:
    print(dp[length - 1])
