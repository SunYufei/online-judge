/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
  public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        int l = 2, r = x >> 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (m == x / m)
                return m;
            else if (m < x / m)
                l = m + 1;
            else
                r = m - 1;
        }
        return r;
    }
};
// @lc code=end
