#include <stdio.h>

int main() {
    int c1, c2, c;
    int h, m;
    float s;
    scanf("%d%d", &c1, &c2);
    c = c2 - c1;
    h = c / 360000;
    c = c % 360000;
    m = c / 6000;
    s = c % 6000;
    s /= 100;
    if (s - (int)s >= 0.5)
        s = (int)s + 1;
    else
        s = (int)s;
    if (h < 10)
        printf("0%d:", h);
    else
        printf("%d:", h);
    if (m < 10)
        printf("0%d:", m);
    else
        printf("%d:", m);
    if (s < 10)
        printf("0%.0f", s);
    else
        printf("%.0f", s);
    return 0;
}
