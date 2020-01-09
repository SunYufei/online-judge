#include <stdio.h>

int main() {
    int n, k, i, j, cur = 0;
    int a[110];
    scanf("%d%d", &n, &k);

    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    for (i = n - 1; i > 0; --i) {
        for (j = 0; j < i; ++j) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
        ++cur;
        if (cur == k)
            break;
    }

    for (i = 0; i < n - 1; ++i)
        printf("%d ", a[i]);
    printf("%d", a[n - 1]);

    return 0;
}