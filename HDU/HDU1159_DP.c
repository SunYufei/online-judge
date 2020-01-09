#include <stdio.h>
#include <string.h>

char x[1000], y[1000];
int c[1010][1010];

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int i, j, m, n;
    while (~scanf("%s%s", x, y)) {
        m = strlen(x);
        n = strlen(y);
        for (i = 0; i <= m; c[i++][0] = 0)
            ;
        for (i = 1; i <= n; c[0][i++] = 0)
            ;
        for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++) {
                if (x[i - 1] == y[j - 1])
                    c[i][j] = c[i - 1][j - 1] + 1;
                else
                    c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        printf("%d\n", c[m][n]);
    }
    return 0;
}