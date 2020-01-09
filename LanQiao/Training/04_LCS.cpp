#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int LCS(string s1, string s2) {
    if (s1.length() == 0 || s2.length() == 0)
        return 0;
    if (s1[0] == s2[0])
        return LCS(s1.substr(1), s2.substr(1)) + 1;
    else
        return max(LCS(s1.substr(1), s2), LCS(s1, s2.substr(1)));
}

int main() {
    string s1 = "abc";
    string s2 = "xbacd";
    int t = LCS(s1, s2);
    cout << t << endl;
    return 0;
}