#include <stdio.h>

int main() {
    double H;

    scanf("%lf", &H);
    H -= 100;
    H *= 0.9;
    H *= 2;
    printf("%.1lf", H);
    return 0;
}
