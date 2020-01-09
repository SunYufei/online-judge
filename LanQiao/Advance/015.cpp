#include <bits/stdc++.h>
using namespace std;

int main() {
    int c;
    cin >> c;

    int n, m, ans, a[20];
    int i, j;

    while (c--) {
        cin >> n >> m;
        for (i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        ans = 1;
        int p = 0, q = n - 1;
        while (p <= n - 1 && q >= 0 && m > 0) {
            if ((a[p] * a[p + 1] > a[q] * a[q - 1]) && m >= 2) {
                ans *= (a[p] * a[p + 1]);
                p += 2;
                m -= 2;
            } else {
                ans *= a[q];
                q--;
                m--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}