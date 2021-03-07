#include <bits/stdc++.h>
using namespace std;

#define MAXN 50005

struct Edge {
    int v, u;
    int t;
    bool operator<(const Edge& e) const { return t > e.t; }
};

vector<Edge> adj[MAXN];   // agj[v]：与v相连的边
priority_queue<Edge> pq;  // 优先队列，存放横切边
vector<Edge> mst;         // 最小生成树
bool vis[MAXN];           // 访问标志

void prim() {
    // prim算法，计算最小生成树
    visit(1);
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        if (vis[e.v] && vis[e.u])
            continue;
        mst.push_back(e);
        if (!vis[e.v])
            visit(e.v);
        if (!vis[e.u])
            visit(e.u);
    }
}

void visit(int v) {
    // 设置访问标志，并将与v相邻结点（未被访问）的边加入优先队列中
    vis[v] = true;
    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
        if (!vis[(*i).u])
            pq.push(*i);
}

int main() {
    int n, m, root;
    int v, u, t;
    Edge e;
    scanf("%d%d%d", &n, &m, &root);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &v, &u, &t);
        e.v = v;
        e.u = u;
        e.t = t;
        adj[v].push_back(e);
        e.v = u;
        e.u = v;
        adj[u].push_back(e);
    }
    prim();

    int ans = 0;

    for (auto i = mst.begin(); i != mst.end(); i++)
        ans = max(ans, (*i).t);

    printf("%d\n", ans);
    return 0;
}