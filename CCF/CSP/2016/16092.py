n = int(input())
l = list(map(int, input().split()))

r = [5] * 20

for p in l:
    i = 0
    while i < 20 and r[i] < p:
        i += 1
    if i < 20:
        start = i * 5 + 5 - r[i] + 1
        print(' '.join([str(v) for v in range(start, start + p)]))
        r[i] -= p
    else:
        for j in range(20):
            if r[j] > 0 and p > 0:
                start = j * 5 + 5 - r[j] + 1
                print(' '.join([str(v)
                                for v in range(start, start + min(r[j], p))]), end=' ')
                p -= r[j]
                if p > r[j]:
                    r[j] = 0
                else:
                    r[j] -= p
        print()
