#include <bits/stdc++.h>
using namespace std;

int main() {
    int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
    float a4 = 0;
    int n4 = 0;
    bool f2 = false;
    int flag = 1;

    int n, t;
    cin >> n;

    while (n--) {
        cin >> t;

        if (t % 10 == 0)
            a1 += t;
        else if (t % 5 == 1) {
            f2 = true;
            a2 += flag * t;
            flag = -flag;
        } else if (t % 5 == 2)
            a3++;
        else if (t % 5 == 3) {
            n4++;
            a4 += t;
        } else if (t % 5 == 4)
            if (t > a5)
                a5 = t;
    }

    a4 /= n4;

    if (a1)
        cout << a1 << " ";
    else
        cout << "N ";
    if (f2)
        cout << a2 << " ";
    else
        cout << "N ";
    if (a3)
        cout << a3 << " ";
    else
        cout << "N ";
    if (a4 > 1e-8)
        printf("%.1f ", a4);
    else
        cout << "N ";
    if (a5)
        cout << a5;
    else
        cout << "N";
    return 0;
}