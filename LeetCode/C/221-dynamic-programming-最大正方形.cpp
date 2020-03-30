/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]),
                                       dp[i - 1][j - 1]);
                    res = max(res, dp[i][j]);
                }
        return res * res;
    }
};
// @lc code=end
