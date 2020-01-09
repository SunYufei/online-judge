#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    char c;
    string s;

    cin >> n >> c;
    getchar();
    getline(cin, s);
    int len = s.length();
    if (len <= n) {
        int t = n - len;
        while (t--)
            cout << c;
        cout << s;
    } else {
        int t = len - n;
        for (int i = t; i < len; i++)
            cout << s[i];
        cout << endl;
    }
    return 0;
} // main