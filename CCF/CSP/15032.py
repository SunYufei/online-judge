n = int(input())
l = list(map(int, input().split()))

d = {}
for i in l:
    if i in d:
        d[i] += 1
    else:
        d[i] = 1

m = {}
for k in d:
    if d[k] not in m:
        m[d[k]] = []
    m[d[k]].append(k)

keys = sorted(m.keys(), reverse=True)
for k in keys:
    for n in sorted(m[k]):
        print(n, k)
