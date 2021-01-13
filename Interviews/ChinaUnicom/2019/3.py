s = input().split()

d = {}

for i in s:
    t = i.split(':')
    d[t[1]] = t[0]

ans = []

for k in reversed(sorted(d.keys())):
    ans.append(':'.join((d[k], k)))

print(' '.join(ans))
