/*
 * @lc app=leetcode.cn id=367 lang=java
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
    public boolean isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        long t;
        while (l <= r) {
            int m = l + (r - l) / 2;
            t = (long) m * m;
            if (t == num)
                return true;
            else if (t < num)
                l = m + 1;
            else
                r = m - 1;
        }
        return false;
    }
}
// @lc code=end
