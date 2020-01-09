#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    string::iterator it;
    long long ans;
    s.clear();
    ans = 0;
    cin >> s;
    for (it = s.begin(); it < s.end(); it++) {
        ans *= 16;
        if (*it >= 'A')
            ans += (*it - 'A' + 10);
        else
            ans += (*it - '0');
    }
    cout << ans;
    return 0;
}