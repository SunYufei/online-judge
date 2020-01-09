#include <bits/stdc++.h>
using namespace std;

int main() {
    bool flag, p, t;

    int n;
    cin >> n;

    string str;
    int a, b, c;

    while (n--) {
        cin >> str;

        a = b = c = 0;
        flag = true;
        p = t = false;

        for (size_t i = 0; i < str.length(); ++i) {
            if (str[i] == 'P') {
                if (p) {
                    flag = false;
                    break;
                }
                a = i;
                p = true;
            } else if (str[i] == 'A')
                ;
            else if (str[i] == 'T') {
                if (t) {
                    flag = false;
                    break;
                }
                c = str.length() - i - 1;
                b = i - a - 1;
                t = true;
            } else {
                flag = false;
                break;
            }
        }

        if (flag && b != 0 && a * b == c)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}