#include <iostream>
#include <string>
using namespace std;

int main() {
    string s[10] = {"ling", "yi",  "er", "san", "si",
                    "wu",   "liu", "qi", "ba",  "jiu"};
    int i;
    string n;

    cin >> n;
    for (i = 0; i < n.length() - 1; i++) {
        if (n[i] == '-')
            cout << "fu ";
        else
            cout << s[n[i] - '0'] << " ";
    }
    cout << s[n[n.length() - 1] - '0'];
    return 0;
}
