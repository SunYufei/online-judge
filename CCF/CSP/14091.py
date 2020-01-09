n = int(input())
l = sorted(map(int, input().split()))

ans = 0

for i in range(n - 1):
    if l[i + 1] - l[i] == 1:
        ans += 1
print(ans)
