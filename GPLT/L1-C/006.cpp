#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, mul, start = 0, i, j;
    cin >> n;
    int len = 0;
    for (i = 2; i <= sqrt(n); ++i) {
        mul = 1;
        for (j = i; mul * j <= n; ++j) {
            mul *= j;
            if (n % mul == 0 && j - i + 1 > len) {
                start = i;
                len = j - i + 1;
            }
        }
    }
    if (start == 0) {
        start = n;
        len = 1;
    }
    cout << len << endl << start;
    for (i = start + 1; i < start + len; ++i)
        cout << "*" << i;
    return 0;
}