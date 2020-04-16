/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); i++)
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 'a' - 'A';
        return str;
    }
};
// @lc code=end
