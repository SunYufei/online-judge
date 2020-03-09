/*
 * @lc app=leetcode.cn id=121 lang=java
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE;
        int res = 0;
        for (int i : prices) {
            if (i < min)
                min = i;
            else if (i - min > res)
                res = i - min;
        }
        return res;
    }
}
// @lc code=end
