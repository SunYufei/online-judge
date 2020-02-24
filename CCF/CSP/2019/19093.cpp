#include <iostream>
#include <math.h>
#include <string>
using namespace std;

struct RGB {
    int r;
    int g;
    int b;
    RGB(){};
    RGB(int _r, int _g, int _b) { r = _r, g = _g, b = _b; }
} xs[1080][1920];

int to_int(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else
        return c - 'a' + 10;
}

int hex_to_int(string s) {
    int len = s.length();
    int result = 0;
    for (int i = 0; i < len; i++)
        result += to_int(s[i]) * pow(16, len - i - 1);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    int m, n, p, q;
    cin >> m >> n >> p >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string str;
            cin >> str;
            int r, g, b;
            if (str.length() == 7) {
                r = hex_to_int(str.substr(1, 2));
                g = hex_to_int(str.substr(3, 2));
                b = hex_to_int(str.substr(5, 2));
            } else if (str.length() == 4) {
                r = hex_to_int(string(2, str[1]));
                g = hex_to_int(string(2, str[2]));
                b = hex_to_int(string(2, str[3]));
            } else if (str.length() == 2) {
                r = g = b = hex_to_int(string(2, str[1]));
            }
            xs[i][j] = RGB(r, g, b);
        }
    }

    for (int i = 0; i < n; i += q) {
        int pr, pg, pb;
        int r = 0, g = 0, b = 0;
        bool same = false;
        for (int j = 0; j < m; j += p) {
            pr = r, pg = g, pb = b;
            r = g = b = 0;
            for (int ii = i; ii < i + q; ii++) {
                for (int jj = j; jj < j + p; jj++) {
                    r += xs[ii][jj].r;
                    g += xs[ii][jj].g;
                    b += xs[ii][jj].b;
                }
            }
            r /= p * q, g /= p * q, b /= p * q;
            if (pr == r && pg == g && pb == b)
                same = true;
            else
                same = false;
            if (!same) {
                string str = "\\x1B\\x5B";

                if (r == 0 && g == 0 && b == 0) {
                    str += "\\x30\\x6D\\x20";
                } else {
                    str += "\\x34\\x38\\x3B\\x32\\x3B";
                    string sr, sg, sb;
                    sr = to_string(r);
                    sg = to_string(g);
                    sb = to_string(b);
                    for (int k = 0; k < sr.length(); k++)
                        str += "\\x3" + string(1, sr[k]);
                    str += "\\x3B";
                    for (int k = 0; k < sg.length(); k++)
                        str += "\\x3" + string(1, sg[k]);
                    str += "\\x3B";
                    for (int k = 0; k < sb.length(); k++)
                        str += "\\x3" + string(1, sb[k]);
                    str += "\\x6D\\x20";
                }
                cout << str;
            } else {
                cout << "\\x20";
            }
        }
        if (!(r == 0 && g == 0 && b == 0)) {
            cout << "\\x1B\\x5B\\x30\\x6D";
        }
        cout << "\\x0A";
    }
    return 0;
}