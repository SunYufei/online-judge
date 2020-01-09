#include <stdio.h>

int main() {
    int i, j;
    for (i = 1; i < 10; i++)
        for (j = 0; j < 10; j++)
            printf("%d%d%d%d\n", i, j, j, i);
    return 0;
}