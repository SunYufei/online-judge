#include <stdio.h>

int main() {
    int max = -999999, mid = -999999, min = -999999, t, i;
    for (i = 0; i < 3; i++) {
        scanf("%d", &t);
        if (t > max) {
            min = mid;
            mid = max;
            max = t;
        } else if (t > mid) {
            min = mid;
            mid = t;
        } else
            min = t;
    }
    printf("%d %d %d", max, mid, min);
    return 0;
}