#include <stdio.h>

int main() {
    int h, m;
    scanf("%d:%d", &h, &m);
    if (h > 12) {
        printf("%d:%d PM", h - 12, m);
    } else if (h == 12) {
        printf("%d:%d PM", h, m);
    } else {
        printf("%d:%d AM", h, m);
    }

    return 0;
}