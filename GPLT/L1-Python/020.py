n = int(input())

flag = [False] * 100000

for _ in range(n):
    l = list(map(int, input().split()))
    if l[0] != 1:
        for i in range(1, len(l)):
            flag[l[i]] = True

input()

ans = []

l = input().split()

for i in l:
    if flag[int(i)] == False:
        flag[int(i)] = True
        ans.append(i)

if len(ans):
    print(' '.join(map(str, ans)))
else:
    print('No one is handsome')
