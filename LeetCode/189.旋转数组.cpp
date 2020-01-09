/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        vector<int> t = nums;
        for (size_t i = 0; i < nums.size(); i++)
            nums[(i + k) % nums.size()] = t[i];
    }
};
