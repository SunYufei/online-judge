n = int(input())
ans = 0
a = [[False] * 105 for _ in range(105)]
for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(x1, x2):
        for j in range(y1, y2):
            a[i][j] = 1
for i in range(105):
    for j in range(105):
        if a[i][j] == 1:
            ans += 1
print(ans)
