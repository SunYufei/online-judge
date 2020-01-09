#include <bits/stdc++.h>
using namespace std;

const int N = 20011, M = 20011, E = 40011 * 2 + 1;

int n, m, pcnt, qcnt, pedge, head[M], idx[M];

struct Last {
    int id, tk;
} lastW[N];

vector<Last> lastR[N];

struct Edge {
    int ver, next;
} edges[E];

priority_queue<int> que;

struct BitSet {
    const static int N = M / 32 + 5;

    unsigned data[N];

    unsigned &operator[](int a) { return data[a]; }

    const unsigned &operator[](int a) const { return data[a]; }

    bool get(int a) { return (data[a >> 5] >> (a & 31)) & 1; }

    void set(int a) { data[a >> 5] |= 1 << (a & 31); }

    void unset(int a) { data[a >> 5] &= ~(1 << (a & 31)); }

    BitSet &operator|=(const BitSet &a) {
        for (int i = 0; i < N; ++i)
            data[i] |= a[i];
        return *this;
    }
} used[M];

void ins(int a, int b) {
    if (!a || a == b)
        return;
    ++idx[b];
    edges[++pedge] = (Edge){b, head[a]};
    head[a] = pedge;
}

void init() {
    scanf("%d%d%d%d", &n, &m, &pcnt, &qcnt);
    for (int i = 1; i <= pcnt; ++i) {
        int op, xk, tk;
        scanf("%d%d%d", &op, &xk, &tk);
        if (op == 0) {
            ins(lastW[xk].tk, tk);
            lastR[xk].push_back((Last){i, tk});
        } else {
            if (!lastR[xk].empty()) {
                for (auto i = lastR[xk].begin(); i != lastR[xk].end(); ++i)
                    ins(i->tk, tk);
                lastR[xk].clear();
            } else
                ins(lastW[xk].tk, tk);
            lastW[xk] = (Last){i, tk};
        }
    }
}

void solve() {
    for (int i = 1; i <= m; ++i)
        used[i].set(i);
    for (int i = 1; i <= m; ++i)
        if (!idx[i])
            que.push(-i);
    for (int i = 1; i <= m; ++i) {
        int cur = -que.top();
        que.pop();
        printf("%d%c", cur, i == m ? '\n' : ' ');
        for (int j = head[cur]; j; j = edges[j].next) {
            if (!--idx[edges[j].ver])
                que.push(-edges[j].ver);
            used[edges[j].ver] |= used[cur];
        }
    }
    for (int i = 1; i <= qcnt; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%s\n", !used[x].get(y) ? "YES" : "NO");
    }
}

int main() {
    init();
    solve();
    fclose(stdout);
    return 0;
}