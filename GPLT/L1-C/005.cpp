#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, tn, i, m;
    cin >> n;
    string a[n + 1];
    int b[n + 1];
    string t;
    for (i = 0; i < n; i++) {
        cin >> t >> tn;
        a[tn] = t;
        cin >> b[tn];
    }
    cin >> m;
    int c[m];
    for (i = 0; i < m; i++)
        cin >> c[i];
    for (i = 0; i < m; i++)
        cout << a[c[i]] << " " << b[c[i]] << endl;
    return 0;
} // main
