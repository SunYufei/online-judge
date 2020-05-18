#include <stdio.h>

int main() {
    int i, j, k, m, n;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            for (k = 0; k < 2; k++)
                for (m = 0; m < 2; m++)
                    for (n = 0; n < 2; n++)
                        printf("%d%d%d%d%d\n", i, j, k, m, n);
    return 0;
}