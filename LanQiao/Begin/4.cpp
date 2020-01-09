#include <iostream>
using namespace std;

const int MOD = 10007;

long fib(int n) {
    long a = 1, b = 1;
    for (int i = 3; i <= n; i++) {
        b = a + b;
        a = b - a;
        b %= MOD;
        a %= MOD;
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) % MOD;
    return 0;
}