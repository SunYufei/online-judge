#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    vector<string> v;
    while (true) {
        cin >> s;
        if (s[0] != '.')
            v.push_back(s);
        else
            break;
    }
    if (v.size() < 2)
        cout << "Momo... No one is for you ...\n";
    else if (v.size() < 14)
        cout << v[1] << " is the only one for you...\n";
    else
        cout << v[1] << " and " << v[13] << " are inviting you to dinner...\n";
    return 0;
}