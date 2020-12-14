#include "../main.h"

class Solution {
  public:
    int dominantIndex(vector<int> &nums) {
        if (nums.size() == 1)
            return 0;
        int maxNum = INT_MIN, subMax = INT_MIN, idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxNum) {
                subMax = maxNum;
                maxNum = nums[i];
                idx = i;
            } else
                subMax = max(subMax, nums[i]);
        }
        if (maxNum < 2 * subMax)
            return -1;
        return idx;
    }
};