/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if (m * n == 0)
            return m + n;
        vector<vector<int>> dp;
        for (int i = 0; i <= m; i++)
            dp.push_back(vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i - 1][j]),
                                       dp[i][j - 1]);
            }
        return dp[m][n];
    }
};
// @lc code=end
