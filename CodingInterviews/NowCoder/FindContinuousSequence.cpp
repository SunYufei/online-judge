#include "main.h"

class Solution {
  public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        if (sum <= 0)
            return {};
        vector<vector<int>> res;
        int l = 1, r = 2, s = l + r;
        while (sum / 2 + 1 >= r) {
            if (s < sum)
                s += ++r;
            else if (s > sum)
                s -= l++;
            else {
                vector<int> v;
                for (int i = l; i <= r; i++)
                    v.push_back(i);
                res.push_back(v);
                s += ++r;
            }
        }
        return res;
    }
};