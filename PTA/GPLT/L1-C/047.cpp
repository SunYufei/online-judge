#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string name;
    int a, b;
    while (n--) {
        cin >> name >> a >> b;
        if (a < 15 || a > 20 || b < 50 || b > 70)
            cout << name << endl;
    }
    return 0;
}