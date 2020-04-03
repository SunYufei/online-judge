/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
// #include <bits/stdc++.h>
// using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int len = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = len - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back(vector<int>({nums[i], nums[l], nums[r]}));
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
