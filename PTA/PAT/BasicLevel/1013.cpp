#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxn = 1e6, i, j;
    vector<bool> p(maxn + 1, false);
    vector<long> prime;
    for (i = 2; i <= maxn; ++i)
        if (p[i] == false) {
            prime.push_back(i);
            for (j = i + i; j < maxn; j += i)
                p[j] = true;
        }
    int m, n;
    cin >> m >> n;
    for (i = m; i < n; ++i)
        if ((i - m + 1) % 10)
            printf("%ld ", prime[i - 1]);
        else
            printf("%ld\n", prime[i - 1]);
    printf("%ld", prime[n - 1]);
    return 0;
}