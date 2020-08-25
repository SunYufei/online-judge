from collections import defaultdict

n, m = map(int, input().split())

points = defaultdict(list)

for _ in range(n):
    x, y, t = input().split()
    points[t].append((int(x), int(y)))


def test(t0, t1, t2):
    for t in points:
        off = 0
        for x, y in points[t]:
            v = t0 + t1 * x + t2 * y
            if off == 0:
                off = v // abs(v)
            elif off * v < 0:
                return False
    return True


for _ in range(m):
    t0, t1, t2 = map(int, input().split())
    print('Yes' if test(t0, t1, t2) else 'No')
