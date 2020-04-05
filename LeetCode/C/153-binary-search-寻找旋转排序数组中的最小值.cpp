/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int findMin(vector<int> &nums) {
        if (nums[0] > nums[nums.size() - 1]) {
            int l = 0, r = nums.size() - 1;
            while (l <= r) {
                int m = (l + r) >> 1;
                if (nums[m] > nums[m + 1])
                    return nums[m + 1];
                else if (nums[m] < nums[l])
                    r = m - 1;
                else
                    l = m + 1;
            }
        }
        return nums[0];
    }
};
// @lc code=end
