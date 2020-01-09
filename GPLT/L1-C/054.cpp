#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    int n, i, j;
    bool flag = false;

    scanf("%c%d", &c, &n);
    getchar();

    vector<string> a(n);
    for (i = 0; i < n; i++)
        getline(cin, a[i]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] != a[n - 1 - i][n - 1 - j])
                flag = true;
    if (!flag)
        cout << "bu yong dao le\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[n - 1 - i][n - 1 - j] == '@')
                cout << c;
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}