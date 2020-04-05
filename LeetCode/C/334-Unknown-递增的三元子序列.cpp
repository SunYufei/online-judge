/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    bool increasingTriplet(vector<int> &nums) {
        int len = nums.size();
        if (len < 3)
            return false;
        int small = INT_MAX, mid = INT_MAX;
        for (auto num : nums) {
            if (num <= small)
                small = num;
            else if (num <= mid)
                mid = num;
            else if (num > mid)
                return true;
        }
        return false;
    }
};
// @lc code=end
