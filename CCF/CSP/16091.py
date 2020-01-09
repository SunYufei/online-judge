n = int(input())
l = list(map(int, input().split()))
ans = 0
for i in range(n - 1):
    if abs(l[i] - l[i + 1]) > ans:
        ans = abs(l[i] - l[i + 1])
print(ans)
