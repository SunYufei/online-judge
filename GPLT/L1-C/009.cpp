#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

struct frac {
    long long num;
    long long den;

    frac() {
        num = 0;
        den = 1;
    }

    frac(long long n, long long d) {
        long long g = gcd(n, d);
        num = n / g;
        den = d / g;
        if (num == 0)
            den = 1;
    }
};

frac add(frac a, frac b) {
    return frac(a.num * b.den + a.den * b.num, a.den * b.den);
}

void print(frac f) {
    long long d = f.num / f.den;
    f.num %= f.den;
    if (d != 0) {
        cout << d;
        if (f.num != 0)     // only d
            cout << " ";
    }
    if (f.num != 0)
        cout << f.num << "/" << f.den;
    if (d == 0 && f.num == 0)   // 0
        cout << 0;
}

int main() {
    int n;
    cin >> n;
    long long a, b;
    frac sum;
    while (n--) {
        scanf("%lld/%lld", &a, &b);
        sum = add(sum, frac(a, b));
    }
    print(sum);
    return 0;
}