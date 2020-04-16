/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    string reverseStr(string s, int k) {
        if (s.size() <= k) {
            reverse(s.begin(), s.end());
            return s;
        }
        string res;
        if (s.size() <= 2 * k)
            res = s;
        else {
            res = string(s.begin(), s.begin() + 2 * k);
            res += reverseStr(string(s.begin() + 2 * k, s.end()), k);
        }
        reverse(res.begin(), res.begin() + k);
        return res;
    }
};
// @lc code=end
