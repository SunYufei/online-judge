#include <stdio.h>
#include <string.h>
#include <vector>
#define MAXN 1005
using namespace std;
vector<int> G[MAXN];
int reach[MAXN][MAXN];
int vis[MAXN];
int N, M;
int cnt;
void dfs(int cur, int sta) { // sta：起点
    vis[cur] = 1;
    reach[sta][cur] = reach[cur][sta] = 1;
    for (vector<int>::iterator i = G[cur].begin(); i != G[cur].end(); i++) {
        if (vis[*i] == 0) {
            dfs(*i, sta);
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    int u, v;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(i, i);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int j;
        for (j = 1; j <= N; j++) {
            if (reach[i][j] == 0)
                break;
        }
        if (j == N + 1)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}