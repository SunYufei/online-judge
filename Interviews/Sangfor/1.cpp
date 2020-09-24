#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        int a, b1, b2, b3, b4, b5;
        vector<int> c(n + 1);
        for (int i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        for (int i = 0; i < m; i++)
            scanf("%d%d%d%d%d%d", &a, &b1, &b2, &b3, &b4, &b5);
    }
    return 0;
}