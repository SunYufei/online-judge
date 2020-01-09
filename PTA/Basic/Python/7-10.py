y, h = map(int, input().split())

if y < 5:
    ph = 30
else:
    ph = 50

ans = 0

if h <= 40:
    ans += h * ph
else:
    ans += (40 * ph + (h - 40) * ph * 1.5)

print("{0:0.2f}".format(ans))
