n = int(input())
h = list(map(int, input().split()))

ans = 0

for i in range(n):
    t = h[i]
    l, r = i, i
    while l >= 0 and h[l] >= t:
        l -= 1
    while r < n and h[r] >= t:
        r += 1
    ans = max(ans, t * (r - l - 1))

print(ans)