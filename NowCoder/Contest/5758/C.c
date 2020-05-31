#include <stdio.h>

int main() {
    int t, x;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &x);
        double s = x * x + 3.14 * x * x / 2;
        printf("%.2lf\n", s);
    }
    return 0;
}