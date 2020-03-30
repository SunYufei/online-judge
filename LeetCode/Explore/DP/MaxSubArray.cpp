#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int res = INT_MIN;
        int sum = 0;
        for (int num : nums) {
            sum = max(sum + num, num);
            res = max(res, sum);
        }
        return res;
    }
};