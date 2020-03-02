#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();
    while (n--) {
        string str;
        getline(cin, str);
        int len = str.length(), i, count = 0, m1 = 0, m2 = 0;
        if (str[len - 2] == 'g' && str[len - 3] == 'n' && str[len - 4] == 'o')
            m1 = 1;
        for (i = 0; i < len; i++) {
            if (str[i] == ' ')
                count++;
            if (str[i] == ',') {
                if (str[i - 1] == 'g' && str[i - 2] == 'n' && str[i - 3] == 'o')
                    m2 = 1;
            }
        }
        if (m1 == 1 && m2 == 1) {
            for (i = 0; count > 2; i++) {
                if (str[i] == ' ') {
                    count--;
                }
                cout << str[i];
            }
            cout << "qiao ben zhong." << endl;
        } else {
            cout << "Skipped" << endl;
        }
    }
    return 0;
}