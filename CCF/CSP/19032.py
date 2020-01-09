n = int(input())

for _ in range(n):
    s = input()
    s = s.replace('x', '*')
    s = s.replace('/', '//')
    if eval(s) == 24:
        print('Yes')
    else:
        print('No')
