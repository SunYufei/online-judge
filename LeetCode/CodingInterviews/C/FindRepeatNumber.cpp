#include "main.h"

class Solution {
   public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums)
            if (s.insert(num).second == false)
                return num;
        return nums[0];
    }

    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            while (nums[i] != i) {
                int t = nums[i];
                if (t == nums[t])
                    return t;
                nums[i] = nums[t];
                nums[t] = t;
            }
        return INT_MAX;
    }
};