r, y, g = map(int, input().split())
n = int(input())
ans = 0
for _ in range(n):
    k, t = map(int, input().split())
    if k == 0:
        ans += t
    elif k == 1:
        ans += t
    elif k == 2:
        ans = ans + t + r
    elif k == 3:
        pass
print(ans)
