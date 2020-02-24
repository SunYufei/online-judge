n = int(input())
a = sorted(map(int, input().split()), reverse=True)

mid = 0

if n % 2 == 1:
    mid = a[(n - 1) // 2]
else:
    mid = (a[n // 2 - 1] + a[n // 2]) / 2
    if int(mid) == mid:
        mid = int(mid)

print(' '.join(map(str, [a[0], mid, a[-1]])))
