/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > 0)
                nums[i] += nums[i - 1];
            res = max(res, nums[i]);
        }
        return res;
    }
};
// @lc code=end
