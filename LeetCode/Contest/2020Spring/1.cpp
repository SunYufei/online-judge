#include "../main.h"

class Solution {
  public:
    int minCount(vector<int> coins) {
        int res = 0;
        for (auto c : coins)
            res += ceil(c * 1.0 / 2);
        return res;
    }
};
