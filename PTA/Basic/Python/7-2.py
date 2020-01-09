cur, offset = map(int, input().split())
h = cur // 100
m = cur % 100

t = h * 60 + m + offset

print('%d%02d' % (t // 60, t % 60))
