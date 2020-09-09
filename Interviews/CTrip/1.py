pool = input().split()

idx = [0] * len(pool)

while idx[0] < len(pool[0]):
    res = []
    circular = False
    d = {}
    for i, v in enumerate(idx):
        c = pool[i][v]
        if c in d.keys():
            circular = True
        d[c] = True
        res.append(c)
    if circular:
        res.append('--circular dependency')
    print(''.join(res))
    idx[-1] += 1
    for i in range(len(idx) - 1, 0, -1):
        if idx[i] >= len(pool[i]):
            idx[i] = 0
            idx[i - 1] += 1
