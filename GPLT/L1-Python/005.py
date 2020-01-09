#%%
n = int(input())
d = {}
for _ in range(n):
    i = list(map(int, input().split()))
    d[i[1]] = [i[0], i[2]]
_ = input()
m = list(map(int, input().split()))
for i in m:
    print(d[i][0], d[i][1])
