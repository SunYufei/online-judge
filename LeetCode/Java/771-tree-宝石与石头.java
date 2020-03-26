/*
 * @lc app=leetcode.cn id=771 lang=java
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution {
    public int numJewelsInStones(String J, String S) {
        boolean[] hash = new boolean[256];
        for (char c : J.toCharArray())
            hash[c] = true;
        int res = 0;
        for (char c : S.toCharArray())
            if (hash[c])
                ++res;
        return res;
    }
}
// @lc code=end
