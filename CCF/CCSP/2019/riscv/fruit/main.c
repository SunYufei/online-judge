#include "../lib/lib.h"

struct Input {
    int n;
    int A[400];
} input;

int *fruit(int n, int *a, int *b);

int main() {
    loaddata(&input);
    int *ans = fruit(input.n, input.A - 1, input.A + 2*input.n - 1);
    setanswer(ans+1);
    return 0;
}
