n = int(input())
l = list(map(int, input().split()))
ans = 0
for i in range(1, n - 1):
    if l[i - 1] > l[i] and l[i + 1] > l[i]:
        ans += 1
    elif l[i - 1] < l[i] and l[i + 1] < l[i]:
        ans += 1
print(ans)
