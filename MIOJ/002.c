#include <stdio.h>

int main() {
    int res = 0, t;
    while (scanf("%d", &t) != EOF)
        res ^= t;
    printf("%d\n", res);
    return 0;
}