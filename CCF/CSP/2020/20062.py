n, a, b = map(int, input().split())

sum = 0
v = []
d = {}

for _ in range(a):
    v.append(map(int, input().split()))

for _ in range(b):
    idx, val = map(int, input().split())
    d[idx] = val

for idx, val in v:
    if idx in d:
        sum += d[idx] * val

print(sum)