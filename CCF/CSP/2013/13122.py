l = input().split('-')

offset = 0
weight = 1

for i in range(3):
    for j in l[i]:
        offset = offset + int(j) * weight
        weight += 1

offset = offset % 11
if offset == 10 and l[3] == 'X':
    print('Right')
elif offset < 10 and str(offset) == l[3]:
    print('Right')
else:
    if offset == 10:
        offset = 'X'
    print('-'.join([l[0], l[1], l[2], str(offset)]))