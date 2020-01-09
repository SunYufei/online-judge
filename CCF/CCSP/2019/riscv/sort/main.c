#include "../lib/lib.h"

struct Input {
    int n;
    int A[100000];
} input;

int *sort(int n, int *A);

int main() {
    loaddata(&input);
    int *ans = sort(input.n, input.A);
    setanswer(ans);
    return 0;
}
