import string

m, n = map(int, input().split())
p, q = map(int, input().split())

raw = [[(0, 0, 0)] * m for _ in range(n)]


def parse_color(color):
    def hex2int(n1, n2):
        return string.hexdigits.index(n1) * 16 + string.hexdigits.index(n2)

    r, g, b = 0, 0, 0
    if len(color) == 2:
        r = g = b = hex2int(color[1], color[1])
    if len(color) == 4:
        r = hex2int(color[1], color[1])
        g = hex2int(color[2], color[2])
        b = hex2int(color[3], color[3])
    if len(color) == 7:
        r = hex2int(color[1], color[2])
        g = hex2int(color[3], color[4])
        b = hex2int(color[5], color[6])
    return r, g, b


for i in range(n):
    for j in range(m):
        raw[i][j] = parse_color(input())

for i in range(0, n, q):

    for j in range(0, m, p):
        pass
