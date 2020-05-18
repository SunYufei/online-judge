#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) { return a > b; }

int main() {
    int n, m, l, r, k, i, j;
    int a[1010], t[1010];
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    while (m--) {
        cin >> l >> r >> k;
        for (i = 0, j = l - 1; j < r; ++i, ++j)
            t[i] = a[j];
        sort(t, t + i, cmp);
        cout << t[k - 1] << endl;
    }
    return 0;
}