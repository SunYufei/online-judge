/*
 * @lc app=leetcode.cn id=69 lang=java
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
    public int mySqrt(int x) {
        if (x < 2)
            return x;

        int l = 2;
        int r = x / 2;

        while (l <= r) {
            int m = l + (r - l) / 2;
            long t = (long) m * m;
            if (t > x)
                r = m - 1;
            else if (t < x)
                l = m + 1;
            else
                return m;
        }

        return r;
    }
}
// @lc code=end
