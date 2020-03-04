#include <stdio.h>

// value
void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

// pointer
void swap_p(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// reference
void swap_ref(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a, b;

    // value
    a = 1, b = 2;
    swap(a, b);
    printf("Value: a = %d, b = %d\n", a, b);

    // pointer
    a = 1, b = 2;
    swap_p(&a, &b);
    printf("Pointer: a = %d, b = %d\n", a, b);

    // reference
    a = 1, b = 2;
    swap_ref(a, b);
    printf("Reference: a = %d, b = %d\n", a, b);

    return 0;
}