#include <bits/stdc++.h>
using namespace std;

int main() {
    string n, s, p;
    cin >> n >> s;
    if (s[0] == '*')
        p += n[0];
    p += s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '*')
            p += s[i - 1];
        p += s[i];
    }
    regex ptn(p);
    smatch m;
    int res = 0;
    if (regex_search(n, m, ptn))
        for (int i = 0; i < m.size(); i++)
            if (n.find(m.str()) == 0)
                res = max(res, int(m.str().size()));
    printf("%d", res);
    return 0;
}