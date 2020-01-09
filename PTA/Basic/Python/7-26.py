s = input()

if len(s) > 0:
    s = s.strip()[:-1]
    print(' '.join(map(str, map(len, s.split()))))
