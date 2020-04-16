/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int pos = 0, n = s.size();
        for (int begin = 0; begin < n; ++begin)
            if (s[begin] != ' ') {
                if (pos != 0)
                    s[pos++] = ' ';
                int end = begin;
                while (end < n && s[end] != ' ')
                    s[pos++] = s[end++];
                reverse(s.begin() + pos - end + begin, s.begin() + pos);
                begin = end;
            }
        s.erase(s.begin() + pos, s.end());
        return s;
    }
};
// @lc code=end
