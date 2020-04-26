#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int base[], int l, int r) {
    int pivot = r, counter = l, i, t;
    for (i = l; i < r; i++)
        if (base[i] < base[pivot])
            swap(&base[counter++], &base[i]);
    swap(&base[pivot], &base[counter]);
    return counter;
}

void quicksort(int base[], int l, int r) {
    if (l < r) {
        int p = partition(base, l, r);
        quicksort(base, l, p - 1);
        quicksort(base, p + 1, r);
    }
}

int main() {
    int n, base[100010], i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &base[i]);

    quicksort(base, 0, n - 1);

    printf("%d", base[0]);
    for (i = 1; i < n; i++)
        printf(" %d", base[i]);
    return 0;
}