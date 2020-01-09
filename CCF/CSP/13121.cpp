#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int s[10010] = {0};

    cin >> n;

    for (int i = 0, t; i < n; i++) {
        cin >> t;
        s[t]++;
    }

    int ans = 0, m = 0;

    for (int i = 0; i < 10010; i++) {
        if (s[i] > m) {
            m = s[i];
            ans = i;
        }
    }

    cout << ans;

    return 0;
}