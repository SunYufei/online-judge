#include "../lib/lib.h"

struct Input {
    int a, b;
} input;

int aplusb(int a, int b);

int main() {
    loaddata(&input);
    int ans = aplusb(input.a, input.b);
    setanswer(&ans);
    return 0;
}
