#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < size - 2; i++) {
            if (nums[i] > 0)
                return res;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = size - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    int one[3] = {nums[i], nums[l], nums[r]};
                    res.push_back(vector<int>(one, one + 3));
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