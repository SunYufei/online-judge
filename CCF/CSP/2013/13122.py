isbn = input().split('-')

offset = 0
weight = 1

for i in range(3):
    for j in isbn[i]:
        offset = offset + int(j) * weight
        weight += 1

offset = offset % 11
if offset == 10 and isbn[3] == 'X':
    print('Right')
elif offset < 10 and str(offset) == isbn[3]:
    print('Right')
else:
    if offset == 10:
        offset = 'X'
    print('-'.join([isbn[0], isbn[1], isbn[2], str(offset)]))
