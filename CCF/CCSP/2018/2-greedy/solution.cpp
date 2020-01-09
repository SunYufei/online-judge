#include <bits/stdc++.h>
using namespace std;

struct edge_type {
    int st, ed, next;
};

struct node_type {
    int id, head, degree;
};

vector<edge_type> edge;
vector<node_type> g;

vector<int> ans;

int n, m;

struct node_info {
    int id, degree, nxt2;

    node_info(int nid = 0, int ndegree = 0, int nnxt2 = 0)
        : id(nid), degree(ndegree), nxt2(nnxt2) {}

    void operator=(const node_info &n) {
        id = n.id;
        degree = n.degree;
        nxt2 = n.nxt2;
    }

    bool operator<(const node_info &n) {
        // id < nxt2 < degree
        if (degree == n.degree) {
            if (nxt2 == n.nxt2)
                return id < n.id;
            else
                return nxt2 < n.nxt2;
        } else {
            return degree < n.degree;
        }
    }
};

template <typename T> struct segtree {
    int n;
    vector<T> a;

    segtree(int num, const vector<T> &b) : n(num) {
        a.resize(num * 4);
        build(b, 1, 0, n - 1);
    }

    void build(const vector<T> &b, int p, int l, int r) {
        if (l == r) {
            a[p] = b[l];
            return;
        }
        int mid = (l + r + 1) / 2;
        build(b, p * 2, l, mid - 1);
        build(b, p * 2 + 1, mid, r);
        if (a[p * 2] < a[p * 2 + 1])
            a[p] = a[p * 2 + 1];
        else
            a[p] = a[p * 2];
    }

    T maxv() { return a[1]; }

    void change(int tp, const T &tmp) { change(tp, tmp, 1, 0, n - 1); }

    void change(int tp, const T &tmp, int p, int l, int r) {
        // b[tp] = tmp
        if (l == r) {
            a[p] = tmp;
            return;
        }
        int mid = (l + r + 1) / 2;
        if (tp < mid)
            change(tp, tmp, p * 2, l, mid - 1);
        else
            change(tp, tmp, p * 2 + 1, mid, r);
        if (a[p * 2] < a[p * 2 + 1])
            a[p] = a[p * 2 + 1];
        else
            a[p] = a[p * 2];
    }

    void del(int tp) {
        T tmp(-1, -1, -1);
        change(tp, tmp, 1, 0, n - 1);
    }
};

void add_edge(int u, int v) {
    edge_type e;
    e.st = u;
    e.ed = v;
    e.next = g[u].head;
    g[u].head = edge.size();
    edge.push_back(e);
    e.st = v;
    e.ed = u;
    e.next = g[v].head;
    g[v].head = edge.size();
    edge.push_back(e);
    ++g[u].degree;
    ++g[v].degree;
}

void read_data() {
    scanf("%d%d", &n, &m);
    g.resize(n);

    for (int i = 0; i < n; ++i) {
        g[i].id = i;
        g[i].head = -1;
        g[i].degree = 0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u - 1, v - 1);
    }
}

void bdone_del(int u, vector<node_info> &b, vector<bool> &del,
               priority_queue<int, vector<int>, greater<int>> &que0,
               priority_queue<int, vector<int>, greater<int>> &que1,
               segtree<node_info> &tree) {
    del[u] = true;
    tree.del(u);
    int j = g[u].head;
    while (j >= 0) {
        int v = edge[j].ed;
        if (!del[v]) {
            --b[v].degree;
            if (b[u].degree == 2)
                --b[v].nxt2;
            tree.change(v, b[v]);
            if (b[v].degree == 2 || b[v].degree == 1)
                // deleting edge from linked list will be better
                for (int k = g[v].head; k >= 0; k = edge[k].next) {
                    int w = edge[k].ed;
                    if (!del[w]) {
                        b[w].nxt2 += (b[v].degree * 2 - 3);
                        tree.change(w, b[w]);
                    }
                }
            if (b[v].degree == 1)
                que1.push(v);
            else if (b[v].degree == 0)
                que0.push(v);
        }
        j = edge[j].next;
    }
}

void bdone() {
    vector<node_info> b;
    b.resize(n);
    for (int i = 0; i < n; i++) {
        b[i].id = i;
        b[i].degree = g[i].degree;
        b[i].nxt2 = 0;
    }
    for (int i = 0; i < n; i++)
        if (g[i].degree == 2) {
            for (int j = g[i].head; j >= 0; j = edge[j].next)
                ++b[edge[j].ed].nxt2;
        }
    segtree<node_info> tree(n, b);
    vector<bool> del;
    del.resize(n);
    for (int i = 0; i < n; i++)
        del[i] = false;
    priority_queue<int, vector<int>, greater<int>> que0;
    priority_queue<int, vector<int>, greater<int>> que1;
    for (int i = 0; i < n; i++)
        if (b[i].degree == 0) {
            del[i] = true;
            tree.del(i);
            ans.push_back(i);
        } else if (b[i].degree == 1)
            que1.push(i);
    while (true) {
        if (!que0.empty()) {
            int u = que0.top();
            que0.pop();
            if (del[u])
                continue;
            del[u] = true;
            tree.del(u);
            ans.push_back(u);
        } else if (!que1.empty()) {
            int u = que1.top();
            que1.pop();
            if (b[u].degree == 0 || del[u])
                continue;
            int v;
            for (int j = g[u].head; j >= 0; j = edge[j].next) {
                v = edge[j].ed;
                if (!del[v])
                    break;
            }
            bdone_del(u, b, del, que0, que1, tree);
            bdone_del(v, b, del, que0, que1, tree);
            ans.push_back(u);
        } else {
            int tid = tree.maxv().id;
            if (tid == -1)
                break;
            else
                bdone_del(tid, b, del, que0, que1, tree);
        }
    }
}

void output() {
    for (int i = 0; i < ans.size(); i++)
        printf("%d\n", ans[i] + 1);
}

int main() {
    read_data();
    bdone();
    output();
    return 0;
}