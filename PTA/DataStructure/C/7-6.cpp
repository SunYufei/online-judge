#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int MAXN = 15;

int n;
bool edge[MAXN][MAXN] = {false};
bool v[MAXN];

void dfs(int x) {
    printf(" %d", x);
    for (int i = 0; i < n; ++i)
        if (v[i] == false && edge[x][i] == true) {
            v[i] = true;
            dfs(i);
        }
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int y = q.front();
        printf(" %d", y);
        q.pop();
        for (int i = 0; i < n; ++i) {
            if (v[i] == false && edge[y][i] == true) {
                v[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int e, x, y;
    cin >> n >> e;
    while (e--) {
        cin >> x >> y;
        edge[x][y] = edge[y][x] = true;
    }

    for (int i = 0; i < n; ++i)
        v[i] = false;
    for (int i = 0; i < n; ++i) {
        if (v[i] == false) {
            v[i] = true;
            printf("{");
            dfs(i);
            printf(" }\n");
        }
    }

    for (int i = 0; i < n; ++i)
        v[i] = false;
    for (int i = 0; i < n; ++i) {
        if (v[i] == false) {
            v[i] = true;
            printf("{");
            bfs(i);
            printf(" }\n");
        }
    }

    return 0;
}