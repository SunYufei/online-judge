/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.empty())
            return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l + 1 < r && nums[l] == nums[l + 1])
                        ++l;
                    while (l < r - 1 && nums[r] == nums[r - 1])
                        --r;
                    ++l, --r;
                } else if (sum < 0)
                    ++l;
                else
                    --r;
            }
        }
        return res;
    }
};
// @lc code=end
