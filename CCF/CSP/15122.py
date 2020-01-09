n, m = map(int, input().split())

raw = []
ans = []

for _ in range(n):
    item = list(map(int, input().split()))
    raw.append(item)
    ans.append(item.copy())

for i in range(n):
    for j in range(1, m - 1):
        if raw[i][j - 1] == raw[i][j] == raw[i][j + 1]:
            ans[i][j - 1] = ans[i][j] = ans[i][j + 1] = 0

for i in range(1, n - 1):
    for j in range(m):
        if raw[i - 1][j] == raw[i][j] == raw[i + 1][j]:
            ans[i - 1][j] = ans[i][j] = ans[i + 1][j] = 0

for item in ans:
    print(' '.join(map(str, item)))
