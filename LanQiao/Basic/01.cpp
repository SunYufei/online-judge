#include <bits/stdc++.h>
using namespace std;

bool isLeap(int y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }

int main() {
    int y;
    cin >> y;
    if (isLeap(y))
        cout << "yes";
    else
        cout << "no";
    return 0;
}