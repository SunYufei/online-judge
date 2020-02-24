#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, tt, i, j, sub;

    int t = 0, k = 0, p = 0;

    cin >> n >> m;

    for (i = 1; i <= n; ++i) {
        cin >> tt;
        t += tt;
        int sub = 0;
        for (j = 0; j < m; ++j) {
            cin >> tt;
            sub += tt;
        }
        sub = abs(sub);
        if (sub > p) {
            p = sub;
            k = i;
        }
        t = t - sub;
    }

    printf("%d %d %d", t, k, p);

    return 0;
}