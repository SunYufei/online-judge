#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sex, h, w;
    while (n--) {
        cin >> sex >> h >> w;
        if (sex) { // male
            if (h == 130)
                cout << "wan mei! ";
            else if (h < 130)
                cout << "duo chi yu! ";
            else
                cout << "ni li hai! ";
            if (w == 27)
                cout << "wan mei!\n";
            else if (w < 27)
                cout << "duo chi rou!\n";
            else
                cout << "shao chi rou!\n";
        } else { // female
            if (h == 129)
                cout << "wan mei! ";
            else if (h < 129)
                cout << "duo chi yu! ";
            else
                cout << "ni li hai! ";
            if (w == 25)
                cout << "wan mei!\n";
            else if (w < 25)
                cout << "duo chi rou!\n";
            else
                cout << "shao chi rou!\n";
        }
    }
    return 0;
}