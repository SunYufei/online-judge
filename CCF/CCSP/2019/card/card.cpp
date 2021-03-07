#include <string.h>
#include <iostream>
#include <string>
using namespace std;

int n, m;

string c[65];
string s[65];
int types[65];
bool vis[65];

long long u, v;

long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

long long res[65][65];

void init() {
    for (int i = 0; i <= 60; ++i)
        res[i][0] = res[i][i] = 1;
    for (int i = 2; i <= 60; ++i)
        for (int j = 0; j <= i / 2; ++j) {
            res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
            res[i][i - j] = res[i][j];
        }
    long long t = 1;
    for (int i = 1; i <= 60; ++i) {
        t *= i;
        res[i][i] = t;
    }
}

void read_data() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
        if (s[i][0] != '?' && s[i][1] != '?')
            types[i] = 0;
        else if (s[i][0] == '?' && s[i][1] != '?')
            types[i] = 1;
        else
            types[i] = 2;
    }
}

void solve() {
    u = 0;
    v = res[n][m];
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < m; ++i)
        if (types[i] == 0) {
            for (int j = 0; j < n; ++j)
                if (vis[j] == false && s[i][0] == c[j][0] &&
                    s[i][1] == c[j][1]) {
                    ++u;
                    vis[j] = true;
                }
        } else if (types[i] == 1) {
            for (int j = 0; j < n; ++j)
                if (vis[j] == false && s[i][1] == c[j][1]) {
                    ++u;
                    vis[j] = true;
                }
        } else if (types[i] == 2) {
            for (int j = 0; j < n; ++j) {
                if (vis[j] == false) {
                    ++u;
                    vis[j] = true;
                }
            }
        }
}

void output() {
    long long g = gcd(u, v);
    u /= g;
    v /= g;
    printf("%lld/%lld\n", u, v);
}

int main() {
    init();

    int t;
    cin >> t;
    while (t--) {
        read_data();
        solve();
        output();
    }
    return 0;
}