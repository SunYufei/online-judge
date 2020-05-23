/*
    注意题目中的“它们的个数N也是由用户输入的”
    故存在n值不合要求的情况
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n > 0 && n <= 20) {
        map<int, int> num;
        map<int, int>::iterator it;
        int t;
        while (n--) {
            cin >> t;
            num[t] += 1;
        }
        int max_k = 0;
        int max_v = -1;
        for (it = num.begin(); it != num.end(); it++) {
            if (it->second > max_v) {
                max_k = it->first;
                max_v = it->second;
            }
        }
        cout << max_k;
    }
    return 0;
}