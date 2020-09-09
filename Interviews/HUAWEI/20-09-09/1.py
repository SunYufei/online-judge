k = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
n = int(input())
c = list(map(int, input().split()))
d = list(map(int, input().split()))

if n < k:
    print(0)
else:
    i, j = 0, 0
    while i <= n - k:
        j = 0
        while j < k:
            if a[j] == c[i + j] and b[j] == d[i + j]:
                j += 1
            else:
                break
        if j == k:
            break
        else:
            i += j if j > 0 else 1
    if i <= n - k:
        print(i + 1)
    else:
        print(0)
