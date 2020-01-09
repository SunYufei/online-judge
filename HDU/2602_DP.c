#include <stdio.h>
#include <string.h>

int c[1001], w[1001], dp[1001];

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int t, n, v, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &v);
        for (i = 0; i < n; i++)
            scanf("%d", &c[i]);
        for (i = 0; i < n; i++)
            scanf("%d", &w[i]);
        memset(dp, 0, sizeof(dp));
        for (i = 0; i < n; i++)
            for (j = v; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        printf("%d\n", dp[v]);
    }
    return 0;
}
