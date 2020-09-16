from collections import defaultdict

s = input()

d = defaultdict(int)

for c in s:
    d[c] += 1

m = min(d.values())

res = []

for c in s:
    if d[c] != m:
        res.append(c)

print(''.join(res))
