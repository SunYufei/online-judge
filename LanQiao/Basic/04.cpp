#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    vector<int> v;
    v.clear();
    cin >> n;
    while (n--) {
        cin >> t;
        v.push_back(t);
    }
    cout << *max_element(v.begin(), v.end()) << endl;
    cout << *min_element(v.begin(), v.end()) << endl;
    cout << accumulate(v.begin(), v.end(), 0) << endl;
    return 0;
}