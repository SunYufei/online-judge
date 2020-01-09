n = int(input())
a = [int(v) for v in input().split()]
a.sort()

middle = n // 2
before = n // 2
after = n // 2

while before > 0 and a[middle] == a[before - 1]:
    before -= 1
while after < n-1 and a[middle] == a[after + 1]:
    after += 1
if before == n - 1 - after:
    print(a[middle])
else:
    print(-1)
