#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int size = nums.size();
        vector<int> res(size);
        int t = 1;
        for (int i = 0; i < size; i++) {
            res[i] = t;
            t *= nums[i];
        }
        t = 1;
        for (int i = size - 1; i >= 0; --i) {
            res[i] *= t;
            t *= nums[i];
        }
        return res;
    }
};