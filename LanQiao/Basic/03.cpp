#include <math.h>
#include <stdio.h>

int main() {
    char *ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%c", ch[abs(j - i)]);
        printf("\n");
    }
    return 0;
}