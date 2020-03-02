#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    string::iterator it;
    int count = 0;
    cin >> n;
    double ans = 1;
    if (n[n.length() - 1] % 2 == 0)
        ans *= 2.0;
    if (n[0] == '-') {
        ans *= 1.5;
        for (it = n.begin() + 1; it < n.end(); it++) {
            if (*it == '2')
                count++;
        }
        ans *= count;
        ans /= n.length() - 1;
    } else {
        for (it = n.begin(); it < n.end(); it++) {
            if (*it == '2')
                count++;
        }
        ans *= count;
        ans /= n.length();
    }
    printf("%.2lf", ans * 100);
    cout << "%";
    return 0;
} // main
