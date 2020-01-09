#include <stdio.h>

const int MAXN = 55;

int row, col;

char maze[MAXN][MAXN];

bool viss[MAXN][MAXN];
bool vist[MAXN][MAXN];

int sx, sy, tx, ty;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1}; // up down left right

bool outofborder(int x, int y) {
    if (x >= 0 && x < row && y >= 0 && y < col)
        return false;
    return true;
}

void dfss(int x, int y) {
    viss[x][y] = true;
    if (maze[x][y] == 'S' || maze[x][y] == 'T' || maze[x][y] == '+') {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (outofborder(nx, ny) == false && maze[nx][ny] != '#' &&
                viss[nx][ny] == false) {
                dfss(nx, ny);
            }
        }
    } else if (maze[x][y] == '|') {
        for (int i = 0; i < 2; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (outofborder(nx, ny) == false && maze[nx][ny] != '#' &&
                viss[nx][ny] == false) {
                dfss(nx, ny);
            }
        }
    } else if (maze[x][y] == '-') {
        for (int i = 2; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (outofborder(nx, ny) == false && maze[nx][ny] != '#' &&
                viss[nx][ny] == false) {
                dfss(nx, ny);
            }
        }
    } else if (maze[x][y] == '.') {
        int nx = x + dx[1];
        int ny = y + dy[1];
        if (outofborder(nx, ny) == false && maze[nx][ny] != '#' &&
            viss[nx][ny] == false) {
            dfss(nx, ny);
        }
    }
}

void dfst(int x, int y) {
    vist[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!outofborder(nx, ny)) {
            if (i == 0 &&
                (maze[nx][ny] == 'S' || maze[nx][ny] == 'T' ||
                 maze[nx][ny] == '+' || maze[nx][ny] == '|' ||
                 maze[nx][ny] == '.') &&
                vist[nx][ny] == false)
                dfst(nx, ny);
            else if (i == 1 &&
                     (maze[nx][ny] == 'S' || maze[nx][ny] == 'T' ||
                      maze[nx][ny] == '+' || maze[nx][ny] == '|') &&
                     vist[nx][ny] == false)
                dfst(nx, ny);
            else if (i == 2 &&
                     (maze[nx][ny] == 'S' || maze[nx][ny] == 'T' ||
                      maze[nx][ny] == '+' || maze[nx][ny] == '-') &&
                     vist[nx][ny] == false)
                dfst(nx, ny);
            else if (i == 3 &&
                     (maze[nx][ny] == 'S' || maze[nx][ny] == 'T' ||
                      maze[nx][ny] == '+' || maze[nx][ny] == '-') &&
                     vist[nx][ny] == false)
                dfst(nx, ny);
        }
    }
}

int main() {
    scanf("%d%d", &row, &col);
    getchar();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            maze[i][j] = getchar();
            if (maze[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (maze[i][j] == 'T') {
                tx = i;
                ty = j;
            }
        }
        getchar();
    }
    dfss(sx, sy);
    dfst(tx, ty);
    if (viss[tx][ty] == 0) {
        printf("I'm stuck!\n");
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (viss[i][j] == 1 && vist[i][j] == 0)
                ++ans;

    printf("%d\n", ans);
    return 0;
}