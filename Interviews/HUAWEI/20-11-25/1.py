from datetime import time

early = {'t': time(5, 0, 0), 'ids': [], 'next': True}
late = {'t': time(0, 0, 0), 'ids': [], 'next': False}

while True:
    try:
        s = input()
        idx, come, go = s.split(' ')

        h, m, s = map(int, [come[0:2], come[3:5], come[6:8]])
        next = False
        if come[8] == 'P' and h != 12:
            h += 12
        if come[8] == 'A' and h < 5:
            next = True
        t = time(h, m, s)
        if early['t'] == t and early['next'] == next:
            early['ids'].append(idx)
        if (early['next'] == True and next == False) or (early['next'] == next
                                                         and t < early['t']):
            early['t'] = t
            early['ids'] = [idx]
            early['next'] = next

        h, m, s = map(int, [go[0:2], go[3:5], go[6:8]])
        next = False
        if go[8] == 'P' and h != 12:
            h += 12
        if go[8] == 'A' and h < 5:
            next = True
        t = time(h, m, s)
        if late['t'] == t and late['next'] == next:
            late['ids'].append(idx)
        if (late['next'] == False and next == True) or (late['next'] == next
                                                        and t > late['t']):
            late['t'] = t
            late['ids'] = [idx]
            late['next'] = next
    except EOFError:
        break

print(' '.join(sorted(early['ids'], key=lambda x: x[1:])))
print(' '.join(sorted(late['ids'], key=lambda x: x[1:])))
