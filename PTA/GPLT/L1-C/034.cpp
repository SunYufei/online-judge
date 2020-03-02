#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, t;
    int f[1001] = {0};

    cin >> n;
    while (n--) {
        cin >> k;
        while (k--) {
            cin >> t;
            f[t]++;
        }
    }

    int idx = 0, val = 0;

    for (int i = 0; i < 1001; i++)
        if (f[i] >= val) {
            val = f[i];
            idx = i;
        }

    printf("%d %d", idx, val);

    return 0;
}