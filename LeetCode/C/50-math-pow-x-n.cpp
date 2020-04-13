/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
  public:
    double myPow(double x, int n) {
        long b = n;
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }
        double res = 1, t = x;
        for (long i = b; i; i >>= 1) {
            if (i & 1 == 1)
                res *= t;
            t *= t;
        }
        return res;
    }
};
// @lc code=end
