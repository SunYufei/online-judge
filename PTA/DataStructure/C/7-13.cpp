#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> m;
    map<int, int>::iterator it;
    int n, t;
    cin >> n;
    while (n--) {
        cin >> t;
        if (m.count(t) == 0)
            m[t] = 1;
        else
            m[t] += 1;
    }
    for (it = m.begin(); it != m.end(); ++it)
        cout << (*it).first << ":" << (*it).second << endl;
    return 0;
}