n = int(input())

s = list(map(int, input().split()))

c = [0] * 10010

res, count = 0, 0

for i in s:
    c[i] += 1
    if c[i] > count:
        res = i
        count = c[i]
    elif c[i] == count:
        res = min(res, i)

print(res)
