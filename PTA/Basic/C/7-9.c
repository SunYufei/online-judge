#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b)
        putchar('C');
    else if (b == c)
        putchar('A');
    else
        putchar('B');
    return 0;
}