#include "main.h"

class Solution {
   public:
    string minNumber(vector<int>& nums) {
        vector<string> t;
        for (int num : nums)
            t.push_back(to_string(num));
        auto cmp = [](string a, string b) { return a + b < b + a; };
        sort(t.begin(), t.end(), cmp);
        string res;
        for (auto s : t)
            res += s;
        return res;
    }
};