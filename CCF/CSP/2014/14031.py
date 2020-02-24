n = int(input())
l = list(map(int, input().split()))

ans = 0
t = []

for i in l:
    if i in t:
        pass
    elif i * (-1) in t:
        ans += 1
    else:
        t.append(i)
print(ans)
