#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 2)
        printf("%d", n);
    else {
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++) {
            b = a + b;
            a = b - a;
        }
        printf("%d", b);
    }
    return 0;
}