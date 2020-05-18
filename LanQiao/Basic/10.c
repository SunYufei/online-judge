#include <stdio.h>
#include <string.h>

int main() {
    char res[10] = {0};
    int a, p = 8;
    scanf("%d", &a);
    if (a == 0)
        res[p--] = '0';
    while (a != 0) {
        if (a % 16 >= 10)
            res[p--] = a % 16 - 10 + 'A';
        else
            res[p--] = a % 16 + '0';
        a /= 16;
    }
    puts(res + p + 1);
    return 0;
}