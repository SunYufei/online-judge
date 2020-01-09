#include <stdio.h>

int main() {
    float f1, f2;
    int i;
    char c;
    scanf("%f %d %c %f", &f1, &i, &c, &f2);
    printf("%c %d %.2f %.2f", c, i, f1, f2);
    return 0;
}