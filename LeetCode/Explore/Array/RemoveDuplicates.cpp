#include "main.h"

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        int p = 0;
        for (int i = 0; i < size; i++)
            if (nums[i] != nums[p])
                nums[++p] = nums[i];
        return p + 1;
    }
};