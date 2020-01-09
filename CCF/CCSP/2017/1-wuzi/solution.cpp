#include <iostream>
#include <string>
using namespace std;

const int MAXN = 45;

int n;
short data[MAXN * MAXN];

int nx[4] = {1, 0, 1, 1};
int ny[4] = {0, -1, -1, 1};

void read_data() {
    scanf("%d\n", &n);

    string str;

    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        for (int j = 0; j < n; ++j) {
            if (str[j] == 'w')
                data[i * n + j] = 1;
            else if (str[j] == 'b')
                data[i * n + j] = 2;
            else
                data[i * n + j] = 0;
        }
    }
}

void solve() {
    for (int i = 0; i < n * n; ++i) {
        int x = i % n;
        int y = i / n;

        if (data[i] == 0) {
            int re = 0;
            bool valid = true;

            for (int j = 0; j < 4; ++j) {
                int newv = 0, oldv = 0;
                int l = 0, r = 0;
                int px, py;

                px = x, py = y;
                while (px + nx[j] >= 0 && px + nx[j] < n && py + ny[j] >= 0 &&
                       py + ny[j] < n) {
                    px += nx[j];
                    py += ny[j];
                    if (data[py * n + px] == 1)
                        ++l;
                    else
                        break;
                }

                px = x, py = y;
                while (px - nx[j] >= 0 && px - nx[j] < n && py - ny[j] >= 0 &&
                       py - ny[j] < n) {
                    px -= nx[j];
                    py -= ny[j];
                    if (data[py * n + px] == 1)
                        ++r;
                    else
                        break;
                }

                if (l >= 5)
                    ++oldv;
                if (r >= 5)
                    ++oldv;
                if (l + r >= 4)
                    newv = 1;
                re += newv - oldv;
            }
            if (re > 0)
                printf("%d %d\n", x, y);
        }
    }
}

int main() {
    read_data();
    solve();

    return 0;
}