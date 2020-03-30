#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursion(n, n, "", res);
        return res;
    }

  private:
    void recursion(int left, int right, string s, vector<string> &res) {
        if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }
        if (left > right)
            return;
        if (left > 0)
            recursion(left - 1, right, s + '(', res);
        if (right > 0)
            recursion(left, right - 1, s + ')', res);
    }
};

int main() {
    Solution sol;
    vector<string> res = sol.generateParenthesis(3);
    for (auto str : res)
        cout << str << endl;
    return 0;
}