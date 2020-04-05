/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        if (n != 0)
            backtracking("", n, n);
        return res;
    }

  private:
    vector<string> res;

    void backtracking(string s, int l_rest, int r_rest) {
        if (l_rest == 0 && r_rest == 0) {
            res.push_back(s);
            return;
        }
        if (l_rest > r_rest || l_rest < 0 || r_rest < 0)
            return;
        backtracking(s + '(', l_rest - 1, r_rest);
        backtracking(s + ')', l_rest, r_rest - 1);
    }
};
// @lc code=end
