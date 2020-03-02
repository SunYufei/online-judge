#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int i, max = -1, n;
    int c[27] = {0};
    string s;
    getline(cin, s);
    for (i = 0; i < s.length(); i++) {
        if (islower(s[i]))
            c[s[i] - 'a' + 1]++;
        else if (isupper(s[i]))
            c[s[i] - 'A' + 1]++;
    }
    for (i = 26; i > 0; i--)
        if (c[i] >= max) {
            max = c[i];
            n = i;
        }
    cout << char('a' + n - 1) << " " << max;
    return 0;
}
