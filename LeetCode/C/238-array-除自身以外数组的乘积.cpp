/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> res;
        int t = 1;
        for (int num : nums) {
            res.push_back(t);
            t *= num;
        }
        t = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] *= t;
            t *= nums[i];
        }
        return res;
    }
};
// @lc code=end
