/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j) {
                dp[j] = grid[i][j];
                if (i == m - 1 && j < n - 1)
                    dp[j] += dp[j + 1];
                else if (j == n - 1 && i < m - 1)
                    dp[j] += dp[j];
                else if (i < m - 1 && j < n - 1)
                    dp[j] += min(dp[j], dp[j + 1]);
            }
        return dp[0];
    }
};
// @lc code=end
