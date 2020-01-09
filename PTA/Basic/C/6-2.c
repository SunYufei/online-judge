#include <stdio.h>

#define MAXN 10

double f(int n, double a[], double x);

int main() {
    int n, i;
    double a[MAXN], x;

    scanf("%d %lf", &n, &x);
    for (i = 0; i <= n; i++)
        scanf("% lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

double power(double x, int i) {
    if (i == 0)
        return 1;
    if (i % 2 == 1)
        return x * power(x, i - 1);
    else {
        double t = power(x, i / 2);
        return t * t;
    }
}

double f(int n, double a[], double x) {
    double ans = 0.0;
    int i, j;
    for (i = 0; i <= n; i++) {
        double t = power(x, i);
        ans = ans + a[i] * t;
    }
    return ans;
}
