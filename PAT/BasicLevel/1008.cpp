#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m;
    deque<int> q;
    while (n--) {
        cin >> t;
        q.push_back(t);
    }
    while (m--) {
        q.push_front(q.back());
        q.pop_back();
    }
    for (auto i = q.begin(); i < q.end() - 1; ++i)
        cout << *i << " ";
    cout << q.back();
    return 0;
}