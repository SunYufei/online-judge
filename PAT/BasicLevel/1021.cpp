#include <iostream>
#include <string>
using namespace std;
int main() {
    int c[10] = {0}, i;
    string::iterator it;
    string s;
    cin >> s;
    for (it = s.begin(); it != s.end(); it++)
        c[*it - '0']++;
    for (i = 0; i < 10; i++)
        if (c[i] != 0)
            cout << i << ":" << c[i] << endl;
    return 0;
}
