#include <bits/stdc++.h>
using namespace std;

int main() {
    long a, b, c;
    int d;
    cin >> a >> b >> d;
    c = a + b;
    vector<int> ans;
    do {
        ans.push_back(c % d);
        c /= d;
    } while (c != 0);
    for (auto i = ans.end() - 1; i >= ans.begin(); --i)
        cout << *i;
    return 0;
}