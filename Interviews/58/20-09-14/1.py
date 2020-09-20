from collections import defaultdict

s = input()

d = defaultdict(int)

for c in s:
    d[c] += 1

res = []
for k in sorted(d.keys()):
    res.append('{}={}'.format(k, d[k]))
print(' '.join(res))
