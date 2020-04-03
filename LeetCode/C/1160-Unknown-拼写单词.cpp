/*
 * @lc app=leetcode.cn id=1160 lang=cpp
 *
 * [1160] 拼写单词
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int countCharacters(vector<string> &words, string chars) {
        int ch[26] = {0};
        for (char c : chars)
            ++ch[c - 'a'];
        int res = 0;
        for (string s : words) {
            bool match = true;
            int count[26] = {0};
            for (char c : s)
                if (++count[c - 'a'] > ch[c - 'a']) {
                    match = false;
                    break;
                }
            if (match)
                res += s.length();
        }
        return res;
    }
};
// @lc code=end
