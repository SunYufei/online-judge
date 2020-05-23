#include <stdio.h>

int main() {
    int i, j, n;
    int tri[35][35] = {0};
    tri[1][1] = 1;
    for (i = 2; i <= 34; i++)
        for (j = 1; j <= i; j++)
            tri[i][j] = tri[i - 1][j] + tri[i - 1][j - 1];
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j < i; j++)
            printf("%d ", tri[i][j]);
        printf("%d\n", tri[i][j]);
    }
    return 0;
}