r, y, g = map(int, input().split())
n = int(input())

ans = 0
s = r + y + g


for _ in range(n):
    k, t = map(int, input().split())
    if k == 0:
        ans += t
    else:
        if k == 1:      # red
            t += g
        elif k == 2:    # yellow
            t += (r+g)
        now = (t - ans) % s
        if now > g:
            ans += (now - g)

print(ans)
