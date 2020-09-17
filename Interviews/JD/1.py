import re

s = input()

ptn = re.compile('\\d+')

all = ptn.findall(s)

res = []
for y in all:
    if 1000 <= int(y) <= 3999:
        res.append(y)

print(' '.join(res))
