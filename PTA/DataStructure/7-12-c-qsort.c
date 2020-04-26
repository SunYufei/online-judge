#include <stdio.h>
#include <stdlib.h>

int cmp(int *a, int *b) { return *a - *b; }

int main() {
    int n, base[100010], i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &base[i]);

    qsort(base, n, sizeof(int), cmp);
    
    printf("%d", base[0]);
    for (i = 1; i < n; i++)
        printf(" %d", base[i]);
    return 0;
}