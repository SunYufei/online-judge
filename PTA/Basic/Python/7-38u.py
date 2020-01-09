a, n = map(int, input().split())

ans = 0

for i in range(n):
    ans = ans + (n - i) * a * (10 ** i)

print(ans)
