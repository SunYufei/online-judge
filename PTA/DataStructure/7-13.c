#include <stdio.h>

int main() {
    int count[60] = {0}, n, t, i;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        ++count[t];
    }
    for (i = 0; i <= 50; i++)
        if (count[i] > 0)
            printf("%d:%d\n", i, count[i]);
    return 0;
}