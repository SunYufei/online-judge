a = list(map(int, input().split()))
a.pop(-1)

b = list(map(int, input().split()))
b.pop()

merge = sorted(a + b)
if len(merge) == 0:
    print('NULL')
else:
    print(' '.join(map(str, merge)))
