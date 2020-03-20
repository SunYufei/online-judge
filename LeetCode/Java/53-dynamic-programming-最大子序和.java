/*
 * @lc app=leetcode.cn id=53 lang=java
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        int res = nums[0];
        for (int i = 1; i < nums.length; i++) {
            nums[i] = Math.max(0, nums[i - 1]) + nums[i];
            res = Math.max(res, nums[i]);
        }
        return res;
    }
}
// @lc code=end
