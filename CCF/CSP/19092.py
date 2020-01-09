from collections import Counter

n = int(input())

t = [0] * n
d = [False] * n
e = 0

for i in range(n):
    op = list(map(int, input().split()))[1:]
    t[i] = op[0]
    for j in op[1:]:
        if j > 0:
            if j != t[i]:
                d[i] = True
            t[i] = j
        else:
            t[i] += j

for i in range(1, n - 1):
    if d[i - 1] and d[i] and d[i + 1]:
        e += 1

if d[-1] and d[0] and d[1]:
    e += 1

if d[-2] and d[-1] and d[0]:
    e += 1

print(sum(t), Counter(d)[True], e)
