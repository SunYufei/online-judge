n, m = map(int, input().split())

a = list(map(int, input().split()))
a.insert(0, 0)

for _ in range(m):
    op, x = map(int, input().split())
    if op == 2:
        l = 2**(x - 1)
        r = min(n + 1, 2**x)
        print(' '.join(map(str, a[l:r])))
    elif op == 1:
        t = []
        t.append(a[x])
        if x * 2 <= n:
            t.append(a[x * 2])
        if x * 2 + 1 <= n:
            t.append(a[x * 2 + 1])
        t.sort(reverse=True)
        a[x] = t[0]
        if len(t) >= 2:
            a[x * 2] = t[1]
        if len(t) == 3:
            a[x * 2 + 1] = t[2]
