n, k = map(int, input().split())
a = [int(v) for v in input().split()]
ans = 0
i = 0
while i < n:
    t = 0
    while i < n and t < k:
        t += a[i]
        i += 1
    ans += 1
print(ans)
