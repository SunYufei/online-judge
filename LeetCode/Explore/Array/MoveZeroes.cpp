#include "../main.h"

class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        int size = nums.size();
        for (int a = 0, b = 0; a < nums.size(); a++)
            if (nums[a] != 0)
                swap(nums[a], nums[b++]);
    }
};