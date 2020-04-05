/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
  public:
    bool isPerfectSquare(int num) {
        int t = 1;
        while (num > 0) {
            num -= t;
            t += 2;
        }
        return num == 0;
    }
};
// @lc code=end
