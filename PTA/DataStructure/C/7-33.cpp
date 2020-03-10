#include <iostream>
#include <stdio.h>
using namespace std;

const int MAXN = 1010;

bool edge[MAXN][MAXN] = {false};
bool vis[MAXN] = {false};

int path[MAXN * 2] = {0};
int idx = 0;

int n, m, s;

void dfs(int x) {
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && edge[x][i]) {
            vis[i] = true;
            path[++idx] = i;
            dfs(i);
            path[++idx] = x;
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        edge[x][y] = edge[y][x] = true;
    }

    path[++idx] = s;
    vis[s] = true;
    dfs(s);

    for (int i = 1; i < idx; ++i)
        printf("%d ", path[i]);
    printf("%d", path[idx]);

    bool flag = false;
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            flag = true;

    if (flag)
        printf(" 0");

    return 0;
}