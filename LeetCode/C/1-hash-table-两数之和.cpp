/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> idx;
        for (int i = 0; i < nums.size(); i++) {
            if (idx.count(target - nums[i]) != 0)
                return vector<int>({idx[target - nums[i]], i});
            idx[nums[i]] = i;
        }
        return vector<int>();
    }
};
// @lc code=end
