#include <math.h>
#include <stdio.h>

int main() {
    int n;
    float h, w, s;

    scanf("%d", &n);
    while (n--) {
        scanf("%f%f", &h, &w);
        s = (h - 100) * 0.9 * 2;
        if (abs(s - w) < s * 0.1)
            printf("You are wan mei!\n");
        else if (s > w)
            printf("You are tai shou le!\n");
        else
            printf("You are tai pang le!\n");
    }

    return 0;
} /* main */