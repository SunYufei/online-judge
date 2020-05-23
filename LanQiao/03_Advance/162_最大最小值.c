#include <stdio.h>

int main() {
    int n, t, max = -9999999, min = 9999999;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        min = t < min ? t : min;
        max = t > max ? t : max;
    }
    printf("%d %d", max, min);
    return 0;
}