s = input().upper()
d = {
    'G': 0,
    'P': 0,
    'L': 0,
    'T': 0
}
for i in s:
    if i in d:
        d[i] += 1
n = 0
for i in d:
    n += d[i]
while True:
    for i in ['G', 'P', 'L', 'T']:
        if d[i] != 0:
            print(i, end='')
            d[i] -= 1
            n -= 1
    if n == 0:
        break
