#include <stdio.h>

int main() {
    double a, b, c, d, m, n;
    char op;
    op = getchar();
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    switch (op) {
    case '+':
        a += c;
        b += d;
        printf("%.2lf+%.2lfi", a, b);
        break;
    case '-':
        a -= c;
        b -= d;
        printf("%.2lf+%.2lfi", a, b);
        break;
    case '*':
        m = a * c - b * d;
        n = b * c + a * d;
        printf("%.2lf+%.2lfi", m, n);
        break;
    case '/':
        m = (a * c + b * d) / (c * c + d * d);
        n = (b * c - a * d) / (c * c + d * d);
        printf("%.2lf+%.2lfi", m, n);
        break;
    }
    return 0;
}