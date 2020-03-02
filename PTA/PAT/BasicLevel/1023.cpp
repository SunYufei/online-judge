#include <stdio.h>

int main() {
    int a[10];
    int i;
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for (i = 1; i < 10; i++)
        if (a[i] != 0) {
            printf("%d", i);
            a[i]--;
            break;
        }
    for (i = 0; i < 10; i++)
        if (a[i] != 0)
            while (a[i]--)
                printf("%d", i);
    return 0;
}
