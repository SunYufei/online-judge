package LeetCode.Java;
/*
 * @lc app=leetcode.cn id=88 lang=java
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if (n == 0)
            return;
        int p = m + n - 1;
        int t1 = m - 1, t2 = n - 1;
        while (t1 >= 0 && t2 >= 0) {
            nums1[p--] = (nums1[t1] > nums2[t2] ? nums1[t1--] : nums2[t2--]);
        }
        while (t2 >= 0) {
            nums1[p--] = nums2[t2--];
        }
    }
}
// @lc code=end
