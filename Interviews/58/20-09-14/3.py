money = list(map(int, input().split()))

res = 0

if len(money) <= 5:
    res = sum(money)
else:
    for i in range(32):
        b = bin(i)[2:]
        if len(b) < 5:
            b = '0' * (5 - len(b)) + b
        l, r = 0, -1
        t = 0
        for c in b:
            if c == '0':
                t += money[l]
                l += 1
            else:
                t += money[r]
                r -= 1
        res = max(res, t)

print(res)