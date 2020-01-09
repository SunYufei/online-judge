#include "../lib/lib.h"

struct Input {
    int a, b;
} input;

int amulb(int a, int b);

int main() {
    loaddata(&input);
    int ans = amulb(input.a, input.b);
    setanswer(&ans);
    return 0;
}
