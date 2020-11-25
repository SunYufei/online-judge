m, n = map(int, input().split())

flag = -1

matrix = []

for _ in range(m):
    matrix.append(list(map(int, input().split())))

res = 0

dirs = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]


def dfs(x, y) -> int:
    t = matrix[x][y]
    area = 1
    matrix[x][y] = flag
    for nx, ny in dirs:
        nx, ny = x + nx, y + ny
        if 0 <= nx < m and 0 <= ny < n:
            if matrix[nx][ny] != flag:
                if -2 <= matrix[nx][ny] - t <= 2:
                    area += dfs(nx, ny)
    return area


for i in range(m):
    for j in range(n):
        if matrix[i][j] != flag:
            res = max(res, dfs(i, j))

print(res)