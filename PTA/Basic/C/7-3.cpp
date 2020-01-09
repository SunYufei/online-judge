#include <stdio.h>

int main() {
    char c[3];
    scanf("%s", c);
    int end = 2, i;
    for (i = 2; i >= 0; --i)
        if (c[i] != '0') {
            end = i;
            break;
        }
    for (i = end; i >= 0; --i)
        printf("%c", c[i]);
    return 0;
}