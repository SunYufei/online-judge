/*
 * @lc app=leetcode.cn id=198 lang=java
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
    public int rob(int[] nums) {
        int prevMax = 0;
        int curMax = 0;
        for (int x : nums) {
            int t = curMax;
            curMax = Math.max(prevMax + x, curMax);
            prevMax = t;
        }
        return curMax;
    }
}
// @lc code=end
