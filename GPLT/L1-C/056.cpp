#include <bits/stdc++.h>
using namespace std;

int main() {
    string name, a[110];

    int n, t, i, j, sum = 0;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> name >> t;
        a[t] = name;
        sum += t;
    }
    double avg = sum * 0.5 / n;
    printf("%d ", int(sum));

    int minid, mindet = 1000;
    for (i = 0; i <= 100; i++)
        if (a[i] != "" && abs(avg - i) < mindet) {
            minid = i;
            mindet = abs(avg - i);
        }

    cout << a[minid];

    return 0;
}