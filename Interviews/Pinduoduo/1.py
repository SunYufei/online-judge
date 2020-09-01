from math import floor

n = int(input())

half = (n - 1) / 2

matrix = [[0] * n for _ in range(n)]

for x in range(n):
    for y in range(n):
        if y > half and x + y < n - 1:
            matrix[x][y] = 1
        if x < y < half:
            matrix[x][y] = 2
        if y < x < half:
            matrix[x][y] = 3
        if x > half and x + y < n - 1:
            matrix[x][y] = 4
        if y < half and x + y > n - 1:
            matrix[x][y] = 5
        if half < y < x:
            matrix[x][y] = 6
        if half < x < y:
            matrix[x][y] = 7
        if x < half and x + y > n - 1:
            matrix[x][y] = 8

for line in matrix:
    print(' '.join(map(str, line)))
