#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int A = 0, B = 0;
    bool a = true, b = true;

    getline(cin, s);
    int len = s.length();
    int i;
    for (i = 0; s[i] != ' '; i++) {
        if (s[i] - '0' <= 9 && s[i] - '0' >= 0)
            A = A * 10 + s[i] - '0';
        else {
            a = false;
            break;
        }
    }
    while (s[i] != ' ')
        i++;
    while (s[i] == ' ')
        i++;
    for (; i < len; i++) {
        if (s[i] - '0' <= 9 && s[i] - '0' >= 0)
            B = B * 10 + s[i] - '0';
        else {
            b = false;
            break;
        }
    }
    if (A < 1 || A > 1000)
        a = false;
    if (B < 1 || B > 1000)
        b = false;
    if (a && b)
        cout << A << " + " << B << " = " << A + B << endl;
    else {
        if (a)
            cout << A;
        else
            cout << "?";
        cout << " + ";
        if (b)
            cout << B;
        else
            cout << "?";
        cout << " = ?\n";
    }

    return 0;
} // main