#include <bits/stdc++.h>
using namespace std;

const int K = 10;
const int D = 80 * K;

struct node {
    int N_O_SZ, N_I_SZ;
    int *N_O, *N_I;
    int vis;
    union {
        int L_in[K];
        unsigned int h_in;
    };
    union {
        int L_out[K];
        unsigned int h_out;
    };
    pair<int, int> L_interval;
};

const int MAXM = 20020, MAXN = 20020;

vector<node> nodes;

int vis_cur, cur;
int m, n, p, q;
int lastw[MAXN];
vector<int> lastr[MAXN];

void read_data() {
    scanf("%d%d%d%d", &m, &n, &p, &q);

    nodes.resize(n);

    for (int i = 0; i < m; ++i)
        lastw[i] = -1;

    vector<set<int>> N_O(n), N_I(n);

    int op, mm, nn;

    for (int i = 0; i < p; ++i) {
        scanf("%d%d%d", &op, &mm, &nn);
        --mm;
        --nn;
        if (op == 0) {
            if (lastw[mm] >= 0 && lastw[mm] != nn) {
                N_O[lastw[mm]].insert(nn);
                N_I[nn].insert(lastw[mm]);
            }
            lastr[mm].push_back(nn);
        } else {
            int len = lastr[mm].size();
            if (len > 0) {
                for (int j = 0; j < len; ++j)
                    if (lastr[mm][j] != nn) {
                        N_O[lastr[mm][j]].insert(nn);
                        N_I[nn].insert(lastr[mm][j]);
                    }
                lastr[mm].clear();
            } else {
                if (lastw[mm] >= 0)
                    if (lastw[mm] != nn) {
                        N_O[lastw[mm]].insert(nn);
                        N_I[nn].insert(lastw[mm]);
                    }
            }
            lastw[mm] = nn;
        }
    }
    for (int u = 0; u < n; ++u) {
        set<int>::iterator iter = N_O[u].begin();

        nodes[u].N_O_SZ = N_O[u].size();
        nodes[u].N_O = new int[N_O[u].size()];

        int i = 0;

        while (iter != N_O[u].end()) {
            nodes[u].N_O[i] = *iter;
            ++i;
            ++iter;
        }

        nodes[u].N_I_SZ = N_I[u].size();
        nodes[u].N_I = new int[N_I[u].size()];
        iter = N_I[u].begin();
        i = 0;
        while (iter != N_I[u].end()) {
            nodes[u].N_I[i] = *iter;
            ++i;
            ++iter;
        }
    }
}

int h_in() {
    static int c = 0, r = rand();
    if (c >= (int)nodes.size() / D) {
        c = 0;
        r = rand();
    }
    ++c;
    return r;
}

int h_out() {
    static int c = 0, r = rand();
    if (c >= (int)nodes.size() / D) {
        c = 0;
        r = rand();
    }
    ++c;
    return r;
}

void dfs_in(node &u) {
    u.vis = vis_cur;
    if (u.N_I_SZ == 0)
        u.h_in = h_in() % (K * 32);
    else {
        for (int i = 0; i < K; ++i)
            u.L_in[i] = 0;

        for (int i = 0; i < u.N_I_SZ; ++i) {
            node &v = nodes[u.N_I[i]];

            if (v.vis != vis_cur)
                dfs_in(v);

            if (v.N_I_SZ == 0) {
                int hu = v.h_in;
                u.L_in[(hu >> 5) % K] |= 1 << (hu & 31);
            } else
                for (int j = 0; j < K; ++j)
                    u.L_in[j] |= v.L_in[j];
        }

        int hu = h_in();
        u.L_in[(hu >> 5) % K] |= 1 << (hu & 31);
    }
}

void dfs_out(node &u) {
    u.vis = vis_cur;

    u.L_interval.first = cur++;

    if (u.N_O_SZ == 0)
        u.h_out = h_out() % (K * 32);
    else {
        for (int i = 0; i < K; i++)
            u.L_out[i] = 0;

        for (int i = 0; i < u.N_O_SZ; i++) {
            node &v = nodes[u.N_O[i]];
            if (v.vis != vis_cur)
                dfs_out(v);

            if (v.N_O_SZ == 0) {
                int hu = v.h_out;
                u.L_out[(hu >> 5) % K] |= 1 << (hu & 31);
            } else
                for (int j = 0; j < K; j++) {
                    u.L_out[j] |= v.L_out[j];
                }
        }

        int hu = h_out();
        u.L_out[(hu >> 5) % K] |= 1 << (hu & 31);
    }

    u.L_interval.second = cur;
}

void index_construction() {
    ++vis_cur;
    for (int u = 0; u < nodes.size(); ++u)
        if (nodes[u].N_O_SZ == 0)
            dfs_in(nodes[u]);

    ++vis_cur;
    cur = 0;

    for (int u = 0; u < nodes.size(); ++u)
        if (nodes[u].N_I_SZ == 0)
            dfs_out(nodes[u]);

    long long index_size = 0;
    for (int u = 0; u < nodes.size(); ++u) {
        index_size += nodes[u].N_I_SZ == 0 ? sizeof(nodes[u].h_in)
                                           : sizeof(nodes[u].L_in);
        index_size += nodes[u].N_O_SZ == 0 ? sizeof(nodes[u].h_out)
                                           : sizeof(nodes[u].L_out);
        index_size += sizeof(nodes[u].L_interval);
    }
}

bool reach(node &u, node &v) {
    if (u.L_interval.second < v.L_interval.second)
        return false;
    else if (u.L_interval.first <= v.L_interval.first)
        return true;

    if (v.N_I_SZ == 0)
        return false;

    if (u.N_O_SZ == 0)
        return false;

    if (v.N_O_SZ == 0) {
        if ((u.L_out[v.h_out >> 5] & (1 << (v.h_out & 31))) == 0)
            return false;
    } else
        for (int i = 0; i < K; ++i)
            if ((u.L_out[i] & v.L_out[i]) != v.L_out[i])
                return false;

    if (u.N_I_SZ == 0) {
        if ((v.L_in[u.h_in >> 5] & (1 << (u.h_in & 31))) == 0)
            return false;
    } else
        for (int i = 0; i < K; i++)
            if ((u.L_in[i] & v.L_in[i]) != u.L_in[i])
                return false;

    for (int i = 0; i < u.N_O_SZ; ++i)
        if (nodes[u.N_O[i]].vis != vis_cur) {
            nodes[u.N_O[i]].vis = vis_cur;
            if (reach(nodes[u.N_O[i]], v))
                return true;
        }

    return false;
}

void solve() {
    int idx[MAXN];
    priority_queue<int> que;

    for (int i = 0; i < n; ++i) {
        idx[i] = nodes[i].N_I_SZ;
        if (idx[i] == 0)
            que.push(-i);
    }

    for (int i = 0; i < n; ++i) {
        int tmp = -que.top();
        que.pop();
        if (i > 0)
            putchar(' ');
        printf("%d", tmp + 1);
        for (int j = 0; j < nodes[tmp].N_O_SZ; ++j) {
            int beta = nodes[tmp].N_O[j];
            --idx[beta];
            if (idx[beta] == 0)
                que.push(-beta);
        }
    }

    putchar('\n');
}

void query() {
    int u, v;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &u, &v);
        ++vis_cur;
        if (reach(nodes[v - 1], nodes[u - 1]))
            printf("NO\n");
        else
            printf("YES\n");
    }
}

int main() {
    read_data();
    solve();
    index_construction();
    query();
    return 0;
}