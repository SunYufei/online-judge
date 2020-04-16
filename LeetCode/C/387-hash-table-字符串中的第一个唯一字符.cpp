/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        for (char c : s)
            ++count[c];
        for (int i = 0; i < s.size(); i++)
            if (count[s[i]] == 1)
                return i;
        return -1;
    }
};
// @lc code=end
