#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
    int n;
    string str;
    getline(cin, str);
    cin >> n;

    if (n > str.length())
        n = n % str.length();

    for (auto it = str.begin() + n; it < str.end(); ++it)
        cout << *it;
    for (auto it = str.begin(); it < str.begin() + n; ++it)
        cout << *it;
    return 0;
}