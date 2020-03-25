/*
 * @lc app=leetcode.cn id=892 lang=java
 *
 * [892] 三维形体的表面积
 */

// @lc code=start
class Solution {
    public int surfaceArea(int[][] grid) {
        int n = grid.length;
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                if (v > 0) {
                    res += (v << 2) + 2;
                    res -= i > 0 ? Math.min(v, grid[i - 1][j]) << 1 : 0;
                    res -= j > 0 ? Math.min(v, grid[i][j - 1]) << 1 : 0;
                }
            }
        return res;
    }
}
// @lc code=end
