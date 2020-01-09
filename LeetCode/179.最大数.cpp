/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string largestNumber(vector<int> &nums) {
        size_t n = nums.size();
        vector<string> str(n);
        for (auto i = 0; i < n; ++i)
            str[i] = to_string(nums[i]);
        sort(str.begin(), str.end(), cmp);
        string ans;
        for (auto i = 0; i < n; ++i)
            ans += str[i];
        if (ans[0] == '0')
            return "0";
        else
            return ans;
    }
    static bool cmp(string s1, string s2) { return s1 + s2 > s2 + s1; }
};
