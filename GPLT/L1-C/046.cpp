#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, s = 1, n = 1;
    cin >> x;
    while (s < x) {
        s = s * 10 + 1;
        n++;
    }
    while (true) {
        cout << s / x;
        if (s % x == 0)
            break;
        s = (s % x) * 10 + 1;
        n++;
    }
    cout << " " << n;
    return 0;
}