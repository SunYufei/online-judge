/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (!isalnum(s[l]) && l < r)
                ++l;
            while (!isalnum(s[r]) && l < r)
                --r;
            if (tolower(s[l++]) != tolower(s[r--]))
                return false;
        }
        return true;
    }
};
// @lc code=end
