import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=695 lang=java
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        for (int i = 0; i < grid.length; i++)
            for (int j = 0; j < grid[i].length; j++)
                if (grid[i][j] == 1)
                    res = Math.max(res, dfs(i, j, grid));
        return res;
    }

    private int dfs(int i, int j, int[][] grid) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[i].length || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        int res = 1;
        res += dfs(i + 1, j, grid);
        res += dfs(i - 1, j, grid);
        res += dfs(i, j + 1, grid);
        res += dfs(i, j - 1, grid);
        return res;
    }
}
// @lc code=end
