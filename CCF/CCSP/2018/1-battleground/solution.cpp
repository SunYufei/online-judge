#include <bits/stdc++.h>
using namespace std;

const int N = 1011, M = 50011;
int n, m, ne, q, h, r, hp[M], dist[N][N];
bool data[N][N], used[N][N];

struct Point {
    int x, y;

    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}

    void read() {
        scanf("%d%d", &x, &y);
        ++x;
        ++y;
    }

    int square() { return x * x + y * y; }

    Point operator+(const Point &a) const { return Point(x + a.x, y + a.y); }

    Point operator-(const Point &a) const { return Point(x - a.x, y - a.y); }
} safe, pos[M], que[N * N];

const Point dir[] = {Point(0, 1),  Point(1, 1),  Point(1, 0),
                     Point(1, -1), Point(0, -1), Point(-1, -1),
                     Point(-1, 0), Point(-1, 1), Point(0, 1)};

inline bool dat(const Point &a) {
    if (a.x <= 0 || a.y <= 0 || a.x > n || a.y > n)
        return false;
    return data[a.x][a.y] || (a - safe).square() <= r * r;
}

void init() {
    scanf("%d%d%d%d%d", &n, &m, &ne, &q, &h);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            data[i][j] = true;
    for (int i = 1; i <= ne; i++) {
        Point p;
        p.read();
        data[p.x][p.y] = false;
    }
    for (int i = 1; i <= m; i++)
        pos[i].read();
    for (int i = 1; i <= m; i++)
        hp[i] = h;
}

int bfs(const Point &a) {
    if ((a - safe).square() <= r * r)
        return 0;
    int op = 0;
    que[op = 1] = a;
    used[a.x][a.y] = true;
    dist[a.x][a.y] = 0;
    for (int cl = 1; cl <= op; cl++) {
        Point cur = que[cl];
        int dis = dist[cur.x][cur.y];
        for (int i = 0; i < 8; i++) {
            Point nex = cur + dir[i];
            if (!used[nex.x][nex.y] && dat(nex) &&
                ((i & 1) == 0 || dat(cur + dir[i - 1]) ||
                 dat(cur + dir[i + 1]))) {
                que[++op] = nex;
                used[nex.x][nex.y] = true;
                dist[nex.x][nex.y] = dis + 1;
                if ((nex - safe).square() <= r * r) {
                    for (int j = 1; j <= op; j++)
                        used[que[j].x][que[j].y] = false;
                    return dist[nex.x][nex.y];
                }
            }
        }
    }
    return -1e7;
}

void solve() {
    for (int i = 1; i <= q; ++i) {
        safe.read();
        scanf("%d", &r);
        for (int j = 1; j <= m; ++j) {
            if (hp[j] > 0)
                hp[j] -= bfs(pos[j]);
            pos[j].read();
        }
    }
}

void print() {
    for (int i = 1; i <= m; ++i)
        printf("%d\n", hp[i] <= 0 ? 0 : hp[i]);
}

int main() {
    init();
    solve();
    print();
    return 0;
}