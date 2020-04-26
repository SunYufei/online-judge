#include <stdio.h>

int main() {
    int n, base[100010], i, j, t;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &base[i]);

    for (i = n - 1; i > 0; --i)
        for (j = 0; j < i; ++j)
            if (base[j] > base[j + 1]) {
                t = base[j];
                base[j] = base[j + 1];
                base[j + 1] = t;
            }

    printf("%d", base[0]);
    for (i = 1; i < n; i++)
        printf(" %d", base[i]);
    return 0;
}