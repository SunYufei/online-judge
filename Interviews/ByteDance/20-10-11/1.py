from collections import defaultdict

n, m = map(int, input().split())

s = defaultdict(int)

for _ in range(n):
    x, y = map(int, input().split())
    s[x] += y

d = defaultdict(list)

for k in s:
    d[s[k]].append(k)

res = []

for k in sorted(d.keys(), reverse=True):
    for x in sorted(d[k]):
        if m > 0:
            res.append(x)
            m -= 1
        else:
            break

print(' '.join(map(str, res)))
