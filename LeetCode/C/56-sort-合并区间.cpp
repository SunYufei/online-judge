/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if (res.empty() || res.back()[1] < l)
                res.push_back(vector<int>{l, r});
            else
                res.back()[1] = max(res.back()[1], r);
        }
        return res;
    }
};
// @lc code=end
