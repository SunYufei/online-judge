#include <stdio.h>

int gcd(int m, int n) {
    int t;
    if (m < n) {
        t = m;
        m = n;
        n = t;
    }
    while (n != 0) {
        t = n;
        n = m % n;
        m = t;
    }
    return m;
}

int lcm(int m, int n) { return m * n / gcd(m, n); }

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d", lcm(m, n));
    return 0;
}