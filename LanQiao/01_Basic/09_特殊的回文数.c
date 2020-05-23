#include <stdio.h>

int main() {
    int i, j, k, n;
    scanf("%d", &n);
    for (i = 1; i < 10; i++)
        for (j = 0; j < 10; j++)
            for (k = 0; k < 10; k++)
                if (i + j + k + j + i == n)
                    printf("%d%d%d%d%d\n", i, j, k, j, i);

    for (i = 1; i < 10; i++)
        for (j = 0; j < 10; j++)
            for (k = 0; k < 10; k++)
                if (i + j + k + k + j + i == n)
                    printf("%d%d%d%d%d%d\n", i, j, k, k, j, i);

    return 0;
}