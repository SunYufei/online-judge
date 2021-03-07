#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define MAXN 100005
using namespace std;

struct Edge {
    int from, to, dist;
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};

struct HeapNode {
    int d, u;
    bool operator<(const HeapNode& rhs) const { return d > rhs.d; }
};

vector<Edge> edges;
vector<int> G[MAXN];
bool done[MAXN];
int d[MAXN];
int n, m;

void addEdge(int from, int to, int dist) {
    edges.push_back(Edge(from, to, dist));
    G[from].push_back(edges.size() - 1);
}

void dijkstra(int s) {
    priority_queue<HeapNode> Q;
    for (int i = 0; i < n; i++)
        d[i] = INF;
    d[s] = 0;
    memset(done, 0, sizeof(done));
    Q.push((HeapNode){0, s});
    while (!Q.empty()) {
        HeapNode x = Q.top();
        Q.pop();
        int u = x.u;
        if (done[u])
            continue;
        done[u] = true;
        for (int i = 0; i < G[u].size(); i++) {
            Edge& e = edges[G[u][i]];
            if (d[e.to] > max(d[u], e.dist)) {
                d[e.to] = max(d[u], e.dist);
                Q.push((HeapNode){d[e.to], e.to});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u - 1, v - 1, w);
        addEdge(v - 1, u - 1, w);
    }
    dijkstra(0);
    printf("%d\n", d[n - 1]);
    return 0;
}