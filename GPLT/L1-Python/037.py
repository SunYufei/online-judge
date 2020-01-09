a, b = map(int, input().split())
if b == 0:
    print('{0}/0=Error'.format(a))
else:
    ans = a / b
    if b < 0:
        print('%d/(%d)=%.2f' % (a, b, ans))
    else:
        print('%d/%d=%.2f' % (a, b, ans))
