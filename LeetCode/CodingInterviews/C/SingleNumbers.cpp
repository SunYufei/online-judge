#include "main.h"

class Solution {
   public:
    vector<int> singleNumbers(vector<int>& nums) {
        if (nums.empty())
            return {};
        unordered_set<int> st;
        for (int num : nums)
            if (st.insert(num).second == false)
                st.erase(num);
        vector<int> res;
        for (auto it : st)
            res.push_back(it);
        return res;
    }
};