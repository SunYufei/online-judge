/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        for (int i = 0; i < k; i++)
            clean_queue(i - k, i, nums);
        res.push_back(nums[dq.front()]);
        for (int i = k; i < nums.size(); i++) {
            clean_queue(i - k, i, nums);
            res.push_back(nums[dq.front()]);
        }
        return res;
    }

  private:
    deque<int> dq;
    void clean_queue(int idx, int i, vector<int> &nums) {
        if (!dq.empty() && idx == dq.front())
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
    }
};
// @lc code=end
