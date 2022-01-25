package LeetCode.Java.p27;
/*
 * @lc app=leetcode.cn id=27 lang=java
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            if (nums[i] == val) {
                nums[i--] = nums[len-- - 1];
            }
        }
        return len;
    }
}
// @lc code=end
