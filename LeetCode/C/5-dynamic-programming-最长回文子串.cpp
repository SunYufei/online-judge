/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2)
            return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string res = "";
        for (int i = n - 1; i >= 0; --i)
            for (int j = i; j < n; ++j) {
                dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]);
                if (dp[i][j] && j - i + 1 > res.length())
                    res = s.substr(i, j - i + 1);
            }
        return res;
    }
};
// @lc code=end
