#include <stdio.h>
#include <string.h>

int t[110][110];

int main() {
    int i, j, k, n, m;
    while (~scanf("%d%d", &n, &m)) {
        if (n == 0 || m == 0)
            break;
        memset(t, 0, sizeof(t));
        while (m--) {
            scanf("%d%d", &i, &j);
            scanf("%d", &t[i - 1][j - 1]);
            t[j - 1][i - 1] = t[i - 1][j - 1];
        }
        for (k = 2; k < n; k++)
            for (i = 0; i < n - k; i++)
                for (j = i + 1; j < i + k; j++)
                    if (t[i][j] + t[j][i + k] < t[i][i + k])
                        t[i][i + k] = t[i][j] + t[j][i + k];
        printf("%d\n", t[0][n - 1]);
    }
    return 0;
}