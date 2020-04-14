#include "main.h"

class Solution {
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        unordered_map<int, int> mp;
        for (int num : numbers)
            if (++mp[num] > n / 2)
                return num;
        return 0;
    }
};