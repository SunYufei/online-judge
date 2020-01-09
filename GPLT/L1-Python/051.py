l = list(map(int, input().split()))
p = l[0] * l[1] * 10
if int(p / 10) == p / 10:
    end = '0'
print(''.join([str(round(p / 100, 2)), end]))
