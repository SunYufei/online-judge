s = input()
flag = int(input())
if flag == 0:
    s = s.upper()
n = int(input())
for _ in range(n):
    l = input()
    if flag == 0:
        t = l.upper()
        if s in t:
            print(l)
    else:
        if s in l:
            print(l)
