#include <stdio.h>

bool monkey[1010] = {false};

int main() {
    int n;
    scanf("%d", &n);

    int rest = n;
    int idx = 1;
    int num = 0;

    while (rest > 1) {
        if (monkey[idx] == false) {
            ++num;
            if (num % 3 == 0) {
                monkey[idx] = true;
                --rest;
            }
        }
        if (++idx > n)
            idx = 1;
    }

    for (int i = 1; i <= n; ++i)
        if (monkey[i] == false) {
            printf("%d", i);
            break;
        }

    return 0;
}