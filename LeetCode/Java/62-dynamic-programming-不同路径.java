/*
 * @lc app=leetcode.cn id=62 lang=java
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] step = new int[m + 2][n + 2];
        step[m][n + 1] = 1;

        for (int i = m; i > 0; --i)
            for (int j = n; j > 0; --j)
                step[i][j] = step[i + 1][j] + step[i][j + 1];

        return step[1][1];
    }
}
// @lc code=end
