/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
  public:
    int maxArea(vector<int> &height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int h = height[l] < height[r] ? height[l++] : height[r--];
            res = max(res, h * (r - l + 1));
        }
        return res;
    }
};
// @lc code=end
