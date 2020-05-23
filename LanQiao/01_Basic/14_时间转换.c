#include <stdio.h>

int main() {
    int h = 0, m = 0, s;
    scanf("%d", &s);
    h = s / 3600;
    s %= 3600;
    m = s / 60;
    s %= 60;
    printf("%d:%d:%d", h, m, s);
    return 0;
}