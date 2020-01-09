/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() <= 0)
            return 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        size_t len = nums.size();
        vector<int> dp(len, 1);
        for (size_t i = 1; i < len; i++)
            if (nums[i] - nums[i - 1] == 1)
                dp[i] = dp[i - 1] + 1;
        return *max_element(dp.begin(), dp.end());
    }
};
