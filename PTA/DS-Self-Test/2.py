n = int(input())

v = []
p = [False] * (n + 1)

for i in range(2, n + 1):
    if not p[i]:
        v.append(i)
        for j in range(i + i, n + 1, i):
            p[j] = True

ans = 0
for i in range(1, len(v)):
    if v[i] - v[i - 1] == 2:
        ans += 1

print(ans)
