/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int p = (l + r) >> 1;
            if (nums[p] < nums[r])
                r = p;
            else if (nums[p] > nums[r])
                l = p + 1;
            else
                --r;
        }
        return nums[l];
    }
};
// @lc code=end
