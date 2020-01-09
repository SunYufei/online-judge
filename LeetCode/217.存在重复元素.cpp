/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        map<int, int> mp;
        for (auto it = nums.begin(); it < nums.end(); it++)
            if (mp[*it])
                return true;
            else
                mp[*it]++;
        return false;
    }
};
