#include <iostream>
using namespace std;

int go[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int m, n;
int ans = 0;
int grid[100][100];
bool mark[100][100];

void DFS(int x, int y, int res) {
    for (int i = 0; i < 4; i++) {
        int nx = x + go[i][0];
        int ny = y + go[i][1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
            (grid[nx][ny] < grid[x][y]) && mark[nx][ny] == 0) {
            mark[nx][ny] = 1;
            DFS(nx, ny, res + 1);
            if (res + 1 > ans)
                ans = res + 1;
            mark[nx][ny] = 0;
        }
    }
    return;
}

int main() {
    cin >> m >> n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mark[i][j] == 1)
                continue;
            DFS(i, j, 1);
        }
    }
    cout << ans;
    return 0;
}