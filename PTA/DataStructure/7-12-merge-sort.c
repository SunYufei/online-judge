#include <stdio.h>
#include <stdlib.h>

void merge_sort(int base[], int l, int r) {
    if (l < r) {
        int m = (l + r) >> 1;
        merge_sort(base, l, m);
        merge_sort(base, m + 1, r);
        merge(base, l, m, r);
    }
}

void merge(int base[], int l, int m, int r) {
    int *t = (int *)malloc((r - l + 1) * sizeof(int));
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
        t[k++] = base[i] <= base[j] ? base[i++] : base[j++];
    while (i <= m)
        t[k++] = base[i++];
    while (j <= r)
        t[k++] = base[j++];
    for (k = 0; k < r - l + 1; k++)
        base[l + k] = t[k];
    free(t);
}

int main() {
    int n, base[100010], i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &base[i]);

    merge_sort(base, 0, n - 1);

    printf("%d", base[0]);
    for (i = 1; i < n; i++)
        printf(" %d", base[i]);
    return 0;
}