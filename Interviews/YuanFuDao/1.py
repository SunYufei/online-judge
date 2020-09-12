n, m = map(int, input().split())
half = n // 2
path = [list(map(int, input().split()))]

for _ in range(m):
    t = []
    l, r = path[-1][0:half], path[-1][half:]
    for i in range(half):
        t.append(r[i])
        t.append(l[i])
    if len(r) > len(l):
        t.append(r[-1])
    path.append(t)

    same = True
    for i in range(n):
        if path[0][i] != t[i]:
            same = False
            break
    if same:
        break

if len(path) != m + 1:
    m = m % (len(path) - 1)

print(' '.join(map(str, path[m])))
