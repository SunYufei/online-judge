#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string d("Dang");
    int h, m;
    cin >> h;
    getchar();
    cin >> m;
    if (h <= 12) {
        cout << "Only ";
        if (h < 10) {
            cout << "0";
        }
        cout << h << ":";
        if (m < 10) {
            cout << "0";
        }
        cout << m << ".  Too early to Dang.";
    } else {
        int dis = h - 12;
        if (m > 0)
            dis++;
        while (dis--)
            cout << d;
    }
    return 0;
} // main
