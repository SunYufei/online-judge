n = int(input())
l = list(map(int, input().split()))
ans = 0
for i in range(n):
    min_height = l[i]
    for j in range(i, n):
        min_height = min(l[j], min_height)
        ans = max(ans, (j - i + 1) * min_height)
print(ans)