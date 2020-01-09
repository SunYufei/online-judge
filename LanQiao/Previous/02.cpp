#include <stdio.h>

int n;

int isShape(int i, int j) {
    if (i > (4 * n + 5 + 1) / 2)
        i = 4 * n + 5 + 1 - i;
    if (j > (4 * n + 5 + 1) / 2)
        j = 4 * n + 5 + 1 - j;
    if (i < j) {
        int t = i;
        i = j;
        j = t;
    }
    if (i <= 2 && j <= 2)
        return 0;
    if (i % 2 == 1 && j >= i - 2)
        return 1;
    if (j % 2 == 1 && j != i - 1)
        return 1;
    return 0;
}

int main() {
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n * 4 + 5; i++) {
        for (j = 1; j <= n * 4 + 5; j++) {
            if (isShape(i, j))
                printf("$");
            else
                printf(".");
        }
        printf("\n");
    }
    return 0;
}