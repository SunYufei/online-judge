#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        auto p = nums.begin();
        for (auto it = nums.begin(); it < nums.end(); ++it)
            if (*it != 0)
                swap(*(p++), *it);
        while (p < nums.end())
            *(p++) = 0;
    }
};