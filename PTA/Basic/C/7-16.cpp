#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool vis[10] = {false};

int t[3];

int a;

void dfs(int step) {
    if (step >= 3) {
        int s = 0;
        for (int i = 0; i < 3; ++i) {
            s *= 10;
            s += t[i];
        }
        ans.push_back(s);
        return;
    }

    for (int i = a; i < a + 4; ++i) {
        if (vis[i] == false) {
            t[step] = i;
            vis[i] = true;
            dfs(step + 1);
            vis[i] = false;
        }
    }
}

void show() {
    int count = 0;
    for (auto i = ans.begin(); i < ans.end() - 1; ++i) {
        ++count;
        cout << *i;
        if (count % 6 == 0)
            cout << endl;
        else
            cout << " ";
    }
    cout << *(ans.end() - 1);
    if (count % 6 == 0)
        cout << endl;
}

int main() {
    cin >> a;
    dfs(0);
    show();
    return 0;
}