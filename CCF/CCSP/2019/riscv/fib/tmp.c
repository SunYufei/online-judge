long long fib(long long n, long long m) {
    long long a = 1, b = 1, i;
    for (i = 3; i <= n; ++i) {
        b = a + b;
        a = b - a;
    }
    return b % m;
}