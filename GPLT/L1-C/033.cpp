#include <bits/stdc++.h>
using namespace std;

int main() {
    int y, n, i, j, t;

    cin >> y >> n;

    for (i = y; i <= 3012; i++) {
        set<int> s;
        t = i;
        for (j = 0; j < 4; j++) {
            s.insert(t % 10);
            t /= 10;
        }
        if (s.size() == n) {
            printf("%d %04d", i - y, i);
            break;
        }
    }

    return 0;
}