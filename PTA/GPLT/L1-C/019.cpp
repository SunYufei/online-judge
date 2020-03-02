#include <bits/stdc++.h>
using namespace std;

int main() {
    int ta, tb, n;
    cin >> ta >> tb >> n;
    int a1[110], a2[110], b1[110], b2[110];
    for (int i = 0; i < n; ++i)
        cin >> a1[i] >> a2[i] >> b1[i] >> b2[i];
    int ca = 0, cb = 0;
    int sum;
    for (int i = 0; i < n; ++i) {
        sum = a1[i] + b1[i];
        if (a2[i] == sum && b2[i] != sum) {
            --ta;
            ++ca;
        } else if (a2[i] != sum && b2[i] == sum) {
            --tb;
            ++cb;
        }

        if (ta < 0) {
            cout << "A" << endl << cb << endl;
            break;
        }
        if (tb < 0) {
            cout << "B" << endl << ca << endl;
            break;
        }
    }
    return 0;
}