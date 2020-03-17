/*
 * @lc app=leetcode.cn id=860 lang=java
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int n = bills.length;
        if (n == 0)
            return true;

        if (bills[0] > 5)
            return false;

        int c5 = 0;
        int c10 = 0;

        for (int i : bills) {
            if (i == 5)
                c5++;
            else if (i == 10) {
                c10++;
                if (c5 <= 0)
                    return false;
                else
                    c5--;
            } else {
                int diff = 15;
                if (c10 > 0) {
                    c10--;
                    diff -= 10;
                }
                while (diff > 0 && c5 > 0) {
                    diff -= 5;
                    c5--;
                }
                if (diff > 0)
                    return false;
            }
        }

        return true;
    }
}
// @lc code=end
