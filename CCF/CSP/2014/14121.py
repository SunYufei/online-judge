n = int(input())
l = list(map(int, input().split()))
c = [0] * n
ans = []
for i in l:
    c[i] += 1
    ans.append(c[i])
print(' '.join(map(str, ans)))
