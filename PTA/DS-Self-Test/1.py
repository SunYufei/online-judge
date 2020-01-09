n, c = input().split()
n = int(n)

a = -1
re = 0
tmp = -1

while tmp <= n:
    re = n - tmp
    a += 2
    tmp += 2 * a

a -= 2
t = (a - 1) // 2

for i in range(a):
    for j in range(t - abs(i - t)):
        print(' ', end='')
    for j in range(abs(i - t) * 2 + 1):
        print(c, end='')
    print()

print(re)
