#include <bits/stdc++.h>
using namespace std;

int main() {
    int count[260] = {0};
    int t, i;
    while (cin >> t) {
        count[t]++;
    }
    for (i = 0; i < 260; i++)
        if (count[i] == 1)
            cout << i << endl;
    return 0;
}