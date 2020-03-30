#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        set<int> s;
        for (int num : nums)
            if (s.insert(num).second == false)
                return true;
        return false;
    }
};