/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        while (n > 0 && s[n - 1] == ' ')
            --n;
        for (int i = n - 1; i >= 0; --i)
            if (s[i] == ' ')
                return n - i - 1;
        return n;
    }
};
// @lc code=end
