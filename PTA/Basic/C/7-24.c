#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int num, den;
    scanf("%d/%d", &num, &den);
    int g;
    if (num >= den)
        g = gcd(num, den);
    else
        g = gcd(den, num);
    num /= g;
    den /= g;
    printf("%d/%d", num, den);
    return 0;
}