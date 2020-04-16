/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    string reverseWords(string s) {
        for (int p = 0, c = 0; c <= s.size(); ++c)
            if (c == s.size() || s[c] == ' ') {
                for (int l = p, r = c - 1; l < r; ++l, --r)
                    swap(s[l], s[r]);
                p = c + 1;
            }
        return s;
    }
};
// @lc code=end
