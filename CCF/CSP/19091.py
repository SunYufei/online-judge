n, m = map(int, input().split())

t = 0
k = 0
p = 0

for i in range(1, n + 1):
    op = list(map(int, input().split()))
    sub = abs(sum(op[1:]))
    if sub > p:
        p = sub
        k = i
    t = t + op[0] - sub

print(t, k, p)
