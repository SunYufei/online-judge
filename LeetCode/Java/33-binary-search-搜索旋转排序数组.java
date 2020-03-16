/*
 * @lc app=leetcode.cn id=33 lang=java
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        if (n == 0)
            return -1;
        if (n == 1)
            return nums[0] == target ? 0 : -1;

        int l, r, m;

        // rotate
        int rotate = 0;
        if (nums[0] > nums[n - 1]) {
            l = 0;
            r = n - 1;
            while (l <= r) {
                m = (l + r) / 2;
                if (nums[m] > nums[m + 1]) {
                    rotate = m + 1;
                    break;
                } else if (nums[m] < nums[l])
                    r = m - 1;
                else
                    l = m + 1;
            }
        }

        // search
        if (rotate == 0) {
            l = 0;
            r = n - 1;
        } else {
            if (nums[0] > target) {
                l = rotate;
                r = n - 1;
            } else {
                l = 0;
                r = rotate - 1;
            }
        }

        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }
}
// @lc code=end
