#include <stdio.h>

int c(int m, int n) {
    if (n < m)
        return 0;
    if (m == 0 || m == n)
        return 1;
    return c(m, n - 1) + c(m - 1, n - 1);
}

int main() {
    int sum = c(5, 10);
    printf("%d", sum);
    return 0;
}