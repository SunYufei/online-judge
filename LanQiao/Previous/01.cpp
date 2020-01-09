#include <stdio.h>

int max(int a, int b, int c) {
    a = a > b ? a : b;
    return a > c ? a : c;
}

int main() {
    int a, b, c, i;
    scanf("%d%d%d", &a, &b, &c);
    for (i = max(a, b, c); i <= 30 * 30 * 30; i++)
        if (i % a == 0 && i % b == 0 && i % c == 0)
            break;
    printf("%d", i);
    return 0;
}