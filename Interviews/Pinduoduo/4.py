n, m = map(int, input().split())

l = [False] * (n + 10)

count = 0
for _ in range(m):
    y = int(input())
    i = 1
    while i * y <= n:
        if not l[i * y]:
            count += 1
        l[i * y] = True
        i += 1

print(count)
