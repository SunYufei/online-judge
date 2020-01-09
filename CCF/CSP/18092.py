l = [False] * 1000010
n = int(input())
ans = 0
for _ in range(n):
    a, b = map(int, input().split())
    for i in range(a, b):
        l[i] = True
for _ in range(n):
    c, d = map(int, input().split())
    for i in range(c, d):
        if l[i] == True:
            ans += 1

print(int(ans))
