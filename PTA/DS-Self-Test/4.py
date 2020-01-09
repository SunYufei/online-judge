from collections import defaultdict

n = input()

d = defaultdict(int)

for i in n:
    d[i] += 1

m = str(int(n) * 2)

dd = defaultdict(int)

for i in m:
    dd[i] += 1

flag = True

for i in dd:
    if i in d:
        if d[i] != dd[i]:
            flag = False
            break
    else:
        flag = False
        break

print('Yes' if flag else 'No')
print(m)
