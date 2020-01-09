#include <iostream>
#include <vector>
using namespace std;

int a[210];
int val[210][210];

int b[210];
vector<int> parent[210];
int ans[110];
int at = 0;

int n;

void read_data() {
    cin >> n;
    // a
    for (int i = 1; i <= 2 * n; ++i)
        cin >> a[i];
    // calc val
    for (int i = 1; i <= n; ++i)
        for (int j = n + 1; j <= 2 * n; ++j)
            val[i][j] = (a[i] ^ a[j]);
    // tree
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> b[i];
        parent[b[i]].push_back(i);
    }
}

vector<int> la, lb;

void leaf(int idx) {
    if (parent[idx].size() == 0) {
        if (idx > n)
            lb.push_back(idx);
        else if (idx > 0)
            la.push_back(idx);
        return;
    }
    for (auto it = parent[idx].begin(); it < parent[idx].end(); ++it)
        leaf(*it);
}

void vec_erase(vector<int> &v, int x) {
    for (auto it = v.begin(); it < v.end(); ++it)
        if (*it == x) {
            v.erase(it);
            break;
        }
}

bool solve() {
    int x = 0, y = 0, cost = -1;

    la.clear();
    lb.clear();
    leaf(0);

    for (auto ita = la.begin(); ita < la.end(); ++ita)
        for (auto itb = lb.begin(); itb < lb.end(); ++itb) {
            if (val[*ita][*itb] > cost) {
                x = *ita;
                y = *itb;
                cost = val[*ita][*itb];
            } else if (val[*ita][*itb] == cost) {
                if (a[*ita] > a[x]) {
                    // max apple value
                    x = *ita;
                    y = *itb;
                    cost = val[*ita][*itb];
                } else if (a[*ita] == a[x]) {
                    // max apple number
                    if (*ita > x) {
                        x = *ita;
                        y = *itb;
                        cost = val[*ita][*itb];
                    } else if (*ita == x) {
                        // max pear number
                        if (*itb > y) {
                            x = *ita;
                            y = *itb;
                            cost = val[*ita][*itb];
                        }
                    }
                }
            }
        }

    if (x != 0 && y != 0 && cost != -1) {
        // erase
        vec_erase(parent[b[x]], x);
        vec_erase(parent[b[y]], y);

        ans[at++] = cost;
        return true;
    } else
        return false;
}

void output() {
    for (int i = 0; i < at - 1; ++i)
        printf("%d ", ans[i]);
    printf("%d", ans[at - 1]);
}

int main() {
    read_data();

    bool flag = true;
    while (flag)
        flag = solve();

    output();

    return 0;
}