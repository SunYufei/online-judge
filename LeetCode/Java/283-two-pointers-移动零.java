/*
 * @lc app=leetcode.cn id=283 lang=java
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;
        for (int i : nums)
            if (i != 0)
                nums[j++] = i;
        for (; j < nums.length; j++)
            nums[j] = 0;
    }
}
// @lc code=end
