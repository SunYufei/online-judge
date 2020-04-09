/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] == target) {
                while (nums[l] < nums[m])
                    ++l;
                while (nums[r] > nums[m])
                    --r;
                return {l, r};
            } else if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return {-1, -1};
    }
};
// @lc code=end
