/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
  public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return pow(x, n);
    }

  private:
    double pow(double x, int n) {
        if (n == 0)
            return 1.0;
        double half = pow(x, n / 2);
        if (n & 1 == 0)
            return half * half;
        else
            return x * half * half;
    }
};
// @lc code=end
