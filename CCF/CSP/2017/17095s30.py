n, m = map(int, input().split())

num = list(map(int, input().split()))

for _ in range(m):
    t = list(map(int, input().split()))
    if t[0] == 1:
        l, r, v = t[1:4]
        for i in range(l - 1, r):
            if num[i] % v == 0:
                num[i] = num[i] / v
    else:
        l, r = t[1:3]
        print(int(sum(num[l - 1:r])))
