#include "main.h"

class Solution {
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k > input.size())
            return {};
        sort(input.begin(), input.end());
        return vector<int>(input.begin(), input.begin() + k);
    }
};