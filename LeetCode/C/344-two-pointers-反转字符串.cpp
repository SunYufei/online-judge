/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    void reverseString(vector<char> &s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            swap(s[l], s[r]);
    }
};
// @lc code=end
