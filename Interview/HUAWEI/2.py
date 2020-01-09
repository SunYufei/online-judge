def fact(num):
    s = 1
    for j in range(1, num + 1):
        s = s * j
    return s


n, m = map(int, input().split())
remain = 0
for i in range(1, m + 1):
    remain = remain + fact(n) / fact(i)

output = fact(n) / fact(m) * remain
print(int(output % 1000000007))
