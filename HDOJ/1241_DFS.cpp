#include <iostream>
using namespace std;

const int MAX = 105;

char map[MAX][MAX];
int m, n;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int x, int y) {
    int i, nx, ny;
    for (i = 0; i < 8; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[nx][ny] == '@') {
            map[nx][ny] = '*';
            dfs(nx, ny);
        }
    }
}

int main() {
    while (cin >> m >> n) {
        if (n == 0 || m == 0)
            break;
        int i, j, count;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                cin >> map[i][j];
        count = 0;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if (map[i][j] == '@') {
                    map[i][j] = '*';
                    count++;
                    dfs(i, j);
                }
        cout << count << endl;
    }
    return 0;
}