/*
 * @lc app=leetcode.cn id=122 lang=java
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int valley;
        int peak;
        int res = 0;
        int i = 0;
        while (i < n - 1) {
            while (i < n - 1 && prices[i] >= prices[i + 1])
                ++i;
            valley = prices[i];
            while (i < n - 1 && prices[i] <= prices[i + 1])
                ++i;
            peak = prices[i];
            res += peak - valley;
        }
        return res;
    }
}
// @lc code=end
