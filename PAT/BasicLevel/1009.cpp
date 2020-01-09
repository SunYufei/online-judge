#include <iostream>
#include <string>
using namespace std;

int main() {
    string s[80];
    int n = -1, i;
    while (cin >> s[++n])
        ;
    for (i = n - 1; i > 0; i--)
        cout << s[i] << " ";
    cout << s[0];
    return 0;
}
