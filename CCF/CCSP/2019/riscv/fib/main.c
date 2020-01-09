#include "../lib/lib.h"

struct Input {
    int n, m;
} input;

int fib(int n, int m);

int main() {
    loaddata(&input);
    int ans = fib(input.n, input.m);
    setanswer(&ans);
    return 0;
}
