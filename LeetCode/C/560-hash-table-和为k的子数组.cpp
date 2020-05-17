/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto num : nums) {
            pre += num;
            if (mp.find(pre - k) != mp.end())
                count += mp[pre - k];
            ++mp[pre];
        }
        return count;
    }
};
// @lc code=end
