#include <iostream>
#include <string>
using namespace std;

int main() {
    int c[4] = {0};
    string s;

    string::iterator it;
    cin >> s;
    for (it = s.begin(); it < s.end(); it++) {
        switch (*it) {
        case 'G':
        case 'g':
            c[0]++;
            break;
        case 'P':
        case 'p':
            c[1]++;
            break;
        case 'L':
        case 'l':
            c[2]++;
            break;
        case 'T':
        case 't':
            c[3]++;
            break;
        }
    }
    while (c[0] + c[1] + c[2] + c[3] != 0) {
        if (c[0] != 0) {
            cout << "G";
            c[0]--;
        }
        if (c[1] != 0) {
            cout << "P";
            c[1]--;
        }
        if (c[2] != 0) {
            cout << "L";
            c[2]--;
        }
        if (c[3] != 0) {
            cout << "T";
            c[3]--;
        }
    }
    return 0;
} // main
