from collections import defaultdict

n = int(input())
s = list(map(int, input().split()))

ans = defaultdict(int)

for i in s:
    ans[i] += 1

k = 0
v = 0
keys = sorted(ans.keys())
for key in keys:
    if ans[key] > v:
        v = ans[key]
        k = key
print(k)
