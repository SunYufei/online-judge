#include <bits/stdc++.h>
using namespace std;

int c[10][26] = {0};
int s[11][27] = {0};

int n, m;
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
    cin >> n >> m;

    string t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        ++c[t[0] - '0'][t[1] - 'A'];
    }

    for (int i = 0; i < m; ++i) {
        cin >> t;
        if (t[0] != '?' && t[1] != '?')
            ++s[t[0] - '0'][t[1] - 'A'];
        else if (t[0] == '?' && t[1] != '?')
            ++s[10][t[1] - 'A'];
        else if (t[0] == '?' && t[1] == '?')
            ++s[10][26];
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 26; ++j)
            cout << c[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 27; ++j)
            cout << c[i][j] << " ";
        cout << endl;
    }
}

void solve() {
    u = 0, v = 1;
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