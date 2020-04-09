#include <stdio.h>

typedef struct {
    int data[2010];
    int length;
} Array;

Array equ1, equ2;
Array mul, add;

int max(int a, int b) { return a > b ? a : b; }

void print(Array array) {
    printf("%d %d", array.data[array.length], array.length);
    int i;
    for (i = array.length - 1; i >= 0; --i)
        if (array.data[i] != 0)
            printf(" %d %d", array.data[i], i);
    printf("\n");
}

int main() {
    int k, a, n, i, j;

    // read equ1
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &a, &n);
        equ1.data[n] = a;
        equ1.length = max(n, equ1.length);
    }

    // read equ2
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &a, &n);
        equ2.data[n] = a;
        equ2.length = max(n, equ2.length);
    }

    // mul
    mul.length = equ1.length + equ2.length;
    for (i = 0; i <= equ1.length; ++i)
        for (j = 0; j <= equ2.length; ++j)
            mul.data[i + j] += equ1.data[i] * equ2.data[j];
    while (mul.data[mul.length] == 0 && mul.length > 0)
        --mul.length;

    print(mul);

    // add
    add.length = max(equ1.length, equ2.length);
    for (i = 0; i <= add.length; ++i)
        add.data[i] = equ1.data[i] + equ2.data[i];
    while (add.data[add.length] == 0 && add.length > 0)
        --add.length;

    print(add);

    return 0;
}