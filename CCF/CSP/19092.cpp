#include <bits/stdc++.h>
using namespace std;

int t[1010] = {0};
bool d[1010] = {false};

int main() {
    int n, m, i, j, tt, ans = 0, e = 0;
    cin >> n;

    for (i = 0; i < n; ++i) {
        cin >> m >> t[i];
        for (j = 1; j < m; ++j) {
            cin >> tt;
            if (tt > 0) {
                if (tt != t[i])
                    d[i] = true;
                t[i] = tt;
            } else if (tt < 0) {
                t[i] += tt;
            }
        }
    }

    for (i = 0; i < 1010; ++i)
        if (d[i])
            ans++;

    for (i = 1; i < n - 1; ++i)
        if (d[i - 1] && d[i] && d[i + 1])
            ++e;

    if (d[n - 1] && d[0] && d[1])
        ++e;

    if (d[n - 2] && d[n - 1] && d[0])
        ++e;

    printf("%d %d %d", accumulate(t, t + 1010, 0), ans, e);

    return 0;
}