a, b = map(int, input().split())
s = 0
c = 0
for i in range(a, b + 1):
    s += i
    c += 1
    if c == 5 or i == b:
        print('%5d\n' % i, end='')
        c = 0
    else:
        print('%5d' % i, end='')
print('Sum = {0}'.format(s))
