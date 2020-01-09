#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    s.clear();
    if (n == 0)
        s = "0";
    while (n != 0) {
        if (n % 16 >= 10)
            s += n % 16 - 10 + 'A';
        else
            s += n % 16 + '0';
        n /= 16;
    }
    reverse(s.begin(), s.end());
    cout << s;
    return 0;
}