board = []
word = str()

while True:
    line = input()
    if line[1] != ',':
        word = line
        break
    else:
        board.append(line.split(','))

m, n = len(board), len(board[0])

if m * n < len(word):
    print('false')
else:

    def bfs(x, y):
        for idx in range(len(word)):
            pass

    res = False
    for i in range(m):
        for j in range(n):
            if board[i][j] == word[0]:
                res = res or bfs(i, j)
    print('true' if res else 'false')
