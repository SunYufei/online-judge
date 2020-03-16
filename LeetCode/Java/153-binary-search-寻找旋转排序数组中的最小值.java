/*
 * @lc app=leetcode.cn id=153 lang=java
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        if (n == 1)
            return nums[0];
        int rotate = 0;
        if (nums[0] > nums[n - 1]) {
            int l = 0;
            int r = n - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (nums[m] > nums[m + 1]) {
                    rotate = m + 1;
                    break;
                } else if (nums[m] < nums[l])
                    r = m - 1;
                else
                    l = m + 1;
            }
        }
        return nums[rotate];
    }
}
// @lc code=end
