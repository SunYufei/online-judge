n, m = map(int, input().split())
l = []
for _ in range(n):
    t = list(map(int, input().split()))
    l.append(t)
t = []
for i in range(m):
    t.clear()
    for j in range(len(l)):
        t.append(l[j][m - i - 1])
    print(' '.join(map(str, t)))
