d = {}

input()
a = list(map(int, input().split()))

for i in a:
    if i in d:
        d[i] += 1
    else:
        d[i] = 1

keys = sorted(d.keys())
for key in keys:
    print('{0}:{1}'.format(key, d[key]))
