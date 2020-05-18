#include <stdio.h>

int main() {
    int n, i, max = -10010, min = 10010, sum = 0, t;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t > max)
            max = t;
        if (t < min)
            min = t;
        sum += t;
    }
    printf("%d\n%d\n%d\n", max, min, sum);
    return 0;
}