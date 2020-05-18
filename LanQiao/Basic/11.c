#include <stdio.h>

int main() {
    long long res = 0;
    char c;
    while (scanf("%c", &c) != EOF) {
        res *= 16;
        if (c >= 'A')
            res += c - 'A' + 10;
        else
            res += c - '0';
    }
    printf("%lld", res);
    return 0;
}