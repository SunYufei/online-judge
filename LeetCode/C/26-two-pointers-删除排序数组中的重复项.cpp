/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        int p = 0;
        for (int num : nums)
            if (nums[p] != num)
                nums[++p] = num;
        return p + 1;
    }
};
// @lc code=end
