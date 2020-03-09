/*
 * @lc app=leetcode.cn id=189 lang=java
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
    public void rotate(int[] nums, int k) {
        if (k == 0|| nums.length <= 1)
            return;
        k = k % nums.length;
        var t = new int[k];
        int i, j;
        for (i = 0, j = nums.length - k; j < nums.length; i++, j++)
            t[i] = nums[j];
        for (i = nums.length - 1; i >= k; --i)
            nums[i] = nums[i - k];
        for (i = 0; i < t.length; i++)
            nums[i] = t[i];
    }
}
// @lc code=end
