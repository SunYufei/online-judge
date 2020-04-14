#include "main.h"

class Solution {
  public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int res = INT_MIN, sum = 0;
        for (int num : array) {
            sum = max(sum + num, num);
            res = max(res, sum);
        }
        return res;
    }
};