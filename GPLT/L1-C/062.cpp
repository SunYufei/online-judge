#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s1, s2;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        s1 = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
        s2 = (s[3] - '0') + (s[4] - '0') + (s[5] - '0');
        if (s1 == s2)
            cout << "You are lucky!\n";
        else
            cout << "Wish you good luck.\n";
    }
    return 0;
}