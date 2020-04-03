/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        int c1[26] = {0}, c2[26] = {0};
        for (char c : s)
            ++c1[c - 'a'];
        for (char c : t)
            if (++c2[c - 'a'] > c1[c - 'a'])
                return false;
        return true;
    }
};
// @lc code=end
