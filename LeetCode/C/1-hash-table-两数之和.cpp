/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> idx;
        for (int i = 0; i < nums.size(); i++) {
            if (idx.count(target - nums[i]) != 0)
                return {idx[target - nums[i]], i};
            idx[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
