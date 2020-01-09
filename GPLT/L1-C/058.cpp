#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    cout << regex_replace(regex_replace(s, regex("6{10,}"), "27"),
                          regex("6{4,}"), "9");
    return 0;
}