#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n < 2)
        printf("%d", n);
    else {
        int p = 0, c = 1, i;
        for (i = 2; i <= n; i++) {
            c = p + c;
            p = c - p;
            c %= 10007;
            p %= 10007;
        }
        printf("%d", c);
    }
    return 0;
}