k = int(input())

a = list(map(int, input().split()))

cur = 0
ans = 0

for i in a:
    cur += i
    if cur > ans:
        ans = cur
    elif cur < 0:
        cur = 0

print(ans)
