/*
 * @lc app=leetcode.cn id=152 lang=java
 *
 * [152] 乘积最大子序列
 */

// @lc code=start
class Solution {
    public int maxProduct(int[] nums) {
        int res = Integer.MIN_VALUE;
        int curMax = 1;
        int curMin = 1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < 0) {
                int t = curMax;
                curMax = curMin;
                curMin = t;
            }
            curMax = Math.max(curMax * nums[i], nums[i]);
            curMin = Math.min(curMin * nums[i], nums[i]);
            res = Math.max(res, curMax);
        }
        return res;
    }
}
// @lc code=end
