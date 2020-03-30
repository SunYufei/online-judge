#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int titleToNumber(string s) {
        int res = 0;
        for (auto it = s.begin(); it < s.end(); ++it) {
            res *= 26;
            res += *(it) - 'A' + 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.titleToNumber("A") << endl;
    cout << sol.titleToNumber("AB") << endl;
    cout << sol.titleToNumber("ZY") << endl;
    return 0;
}