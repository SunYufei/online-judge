
/*
 * @lc app=leetcode.cn id=120 lang=java
 *
 * [120] 三角形最小路径和
 */
import java.util.*;

// @lc code=start
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int m = triangle.size();
        int[] dp = new int[m + 1];
        for (int i = m - 1; i >= 0; --i)
            for (int j = 0; j < triangle.get(i).size(); ++j)
                dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
        return dp[0];
    }
}
// @lc code=end
