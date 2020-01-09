n = int(input())
l = list(map(int, input().split()))
ans = []
for i in range(n):
    if i == 0:
        ans.append(int((l[i] + l[i + 1]) / 2))
    elif i == n - 1:
        ans.append(int((l[i] + l[i - 1]) / 2))
    else:
        ans.append(int((l[i - 1] + l[i] + l[i + 1]) / 3))
print(' '.join(map(str, ans)))
