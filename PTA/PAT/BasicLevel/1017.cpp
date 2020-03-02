#include <bits/stdc++.h>
using namespace std;

struct bign {
    int d[1000];
    int len;

    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign str2bign(string s) {
    bign a;
    for (auto i = s.end() - 1; i >= s.begin(); --i)
        a.d[a.len++] = (*i) - '0';
    return a;
}

bign divide(bign a, int b, int &r) {
    bign q;
    q.len = a.len;
    for (int i = a.len - 1; i >= 0; --i) {
        r = r * 10 + a.d[i];
        if (r < b)
            q.d[i] = 0;
        else {
            q.d[i] = r / b;
            r = r % b;
        }
    }
    while (q.len - 1 >= 1 && q.d[q.len - 1] == 0)
        --q.len;
    return q;
}

int main() {
    string s;
    int b;
    cin >> s >> b;
    bign a = str2bign(s);
    int r;
    bign q = divide(a, b, r);
    for (int i = q.len - 1; i >= 0; --i)
        printf("%d", q.d[i]);
    printf(" %d", r);
    return 0;
}