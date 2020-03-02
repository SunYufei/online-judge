#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int n, i, j, t, re = 0, a = -1, temp = -1;
    char c;

    cin >> n >> c;
    while (temp <= n) {
        re = n - temp;
        a += 2;
        temp += 2 * a;
    }
    a -= 2;
    t = (a - 1) / 2;
    for (i = 0; i < a; i++) {
        for (j = 0; j < t - abs(i - t); j++)
            cout << " ";
        for (j = 0; j < abs(i - t) * 2 + 1; j++)
            cout << c;
        cout << endl;
    }
    cout << re << endl;
    return 0;
} // main
