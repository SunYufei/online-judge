/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        for (int a = 0, b = 0; a < nums.size(); a++)
            if (nums[a] != 0)
                swap(nums[a], nums[b++]);
    }
};
// @lc code=end
