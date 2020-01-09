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

bign change(string str) {
    bign a;
    a.len = str.length();
    for (int i = 0; i < a.len; ++i)
        a.d[i] = str[a.len - i - 1] - '0';
    return a;
}

bign sub(bign a, bign b) {
    bign c;
    for (int i = 0; i < a.len || i < b.len; ++i) {
        if (a.d[i] < b.d[i]) {
            a.d[i + 1] -= 1;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    return c;
}

int main() {
    string str, a, b;
    while (getline(cin, str), str != "") {
        size_t pos = str.find("-");
        a = str.substr(0, pos);
        b = str.substr(pos + 1, str.length() - pos - 1);
        bign aa, bb, c;
        aa = change(a);
        bb = change(b);
        c = sub(aa, bb);
        for (auto i = c.len - 1; i >= 0; --i)
            cout << c.d[i];
        cout << endl;
        break;
    }
    return 0;
}