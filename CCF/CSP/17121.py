n = int(input())
l = sorted(map(int, input().split()))
ans = 10000
for i in range(n - 1):
    if l[i + 1] - l[i] < ans:
        ans = l[i + 1] - l[i]
print(ans)
