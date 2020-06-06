n = int(input())

h = list(map(int, input().split()))

ans = 0

for i in range(n):
    min_height = h[i]
    for j in range(i, n):
        min_height = min(min_height, h[j])
        ans = max(ans, (j - i + 1) * min_height)

print(ans)
