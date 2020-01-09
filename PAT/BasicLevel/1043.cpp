#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int a[6] = {0};
    string s;
    string::iterator it;
    cin >> s;
    for (it = s.begin(); it < s.end(); it++) {
        switch (*it) {
        case 'P':
            a[0]++;
            break;
        case 'A':
            a[1]++;
            break;
        case 'T':
            a[2]++;
            break;
        case 'e':
            a[3]++;
            break;
        case 's':
            a[4]++;
            break;
        case 't':
            a[5]++;
            break;
        }
    }
    while (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] != 0) {
        if (a[0] != 0) {
            putchar('P');
            a[0]--;
        }
        if (a[1] != 0) {
            putchar('A');
            a[1]--;
        }
        if (a[2] != 0) {
            putchar('T');
            a[2]--;
        }
        if (a[3] != 0) {
            putchar('e');
            a[3]--;
        }
        if (a[4] != 0) {
            putchar('s');
            a[4]--;
        }
        if (a[5] != 0) {
            putchar('t');
            a[5]--;
        }
    }
    return 0;
}
