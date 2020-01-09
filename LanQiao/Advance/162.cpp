#include <stdio.h>

int max = -9999999;
int min = 9999999;

int main() {
    int n, t;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        if (t < min)
            min = t;
        if (t > max)
            max = t;
    }
    printf("%d %d", max, min);
    return 0;
}