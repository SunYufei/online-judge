/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int reverse(int x) {
        bool flag = x < 0 ? true : false;
        vector<int> v;
        int t = abs(x);
        while (t) {
            v.push_back(t % 10);
            t /= 10;
        }
        int ans = 0;
        for (auto i = v.begin(); i < v.end(); ++i) {
            ans *= 10;
            ans += *i;
        }
        if (flag)
            ans = -ans;
        return ans;
    }
};
