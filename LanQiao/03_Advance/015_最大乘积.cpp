#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int c, n, m, ans, a[20];
    scanf("%d", &c);

    while (c--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
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
                --q;
                --m;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}