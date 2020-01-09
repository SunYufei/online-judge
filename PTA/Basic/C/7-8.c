#include <stdio.h>

int main() {
    int v;
    scanf("%d", &v);
    printf("Speed: %d - %s", v, v <= 60 ? "OK" : "Speeding");
    return 0;
}