/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
  public:
    bool isPerfectSquare(int num) {
        if (num == 1)
            return true;
        long l = 0, r = num / 2;
        while (l <= r) {
            long m = (l + r) >> 1;
            long square = m * m;
            if (square == num)
                return true;
            else if (square > num)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
};
// @lc code=end
