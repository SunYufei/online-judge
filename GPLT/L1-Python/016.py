m = '10X98765432'

num = '1234567890'

w = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]

ans = []

n = int(input())

for _ in range(n):
    s = input()
    z = 0
    flag = True
    for i in range(17):
        if s[i] not in num:
            ans.append(s)
            flag = False
        else:
            z += w[i] * int(s[i])
    if flag:
        z = z % 11
        if m[z] != s[17]:
            ans.append(s)

if len(ans) == 0:
    print('All passed')
else:
    for i in ans:
        print(i)
