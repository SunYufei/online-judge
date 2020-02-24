#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 105
using namespace std;

char canvas[MAXN][MAXN]; //画布
int m, n;                //画布的宽度、高度
int q;

void drawline(int x1, int y1, int x2, int y2) {
    if (y1 == y2) { //水平线
        if (x1 > x2)
            swap(x1, x2);
        for (int x = x1; x <= x2; x++) {
            if (canvas[y1][x] == '|' || canvas[y1][x] == '+')
                canvas[y1][x] = '+';
            else
                canvas[y1][x] = '-';
        }
    } else if (x1 == x2) { //垂直线
        if (y1 > y2)
            swap(y1, y2);
        for (int y = y1; y <= y2; y++) {
            if (canvas[y][x1] == '-' || canvas[y][x1] == '+')
                canvas[y][x1] = '+';
            else
                canvas[y][x1] = '|';
        }
    }
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void fill(int x, int y, char ch) { // DFS
    canvas[y][x] = ch;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m && canvas[ny][nx] != ch &&
            canvas[ny][nx] != '-' && canvas[ny][nx] != '|' &&
            canvas[ny][nx] != '+') {
            fill(nx, ny, ch);
        }
    }
}

void output() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            printf("%c", canvas[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int op;
    int x1, y1, x2, y2;
    char ch;
    scanf("%d%d%d", &m, &n, &q);
    for (int y = 0; y < n; y++) { //初始全部为点
        for (int x = 0; x < m; x++) {
            canvas[y][x] = '.';
        }
    }
    while (q--) {
        scanf("%d", &op);
        if (op == 0) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            drawline(x1, n - y1 - 1, x2, n - y2 - 1);
        } else if (op == 1) {
            scanf("%d%d %c", &x1, &y1, &ch);
            fill(x1, n - y1 - 1, ch);
        }
    }
    output();
    return 0;
}