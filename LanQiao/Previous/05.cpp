#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    vector<int>::iterator it;
    int m = 0, n = 0, t;
    cin >> t;
    while (cin >> t)
        v.push_back(t);
    sort(v.begin(), v.end());
    for (it = v.begin(); it < v.end() - 1; it++) {
        if (*(it + 1) - *it == 2)
            m = *it + 1;
        if (*(it + 1) - *it == 0)
            n = *it;
        if (m != 0 && n != 0)
            break;
    }
    cout << m << " " << n;
    return 0;
}