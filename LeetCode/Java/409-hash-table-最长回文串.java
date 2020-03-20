/*
 * @lc app=leetcode.cn id=409 lang=java
 *
 * [409] 最长回文串
 */

import java.util.*;

// @lc code=start
class Solution {
    public int longestPalindrome(String s) {
        int[] count = new int[128];
        for (char c : s.toCharArray())
            ++count[c];
        int res = 0;
        for (int v : count) {
            res += v / 2 * 2;
            if (v % 2 == 1 && res % 2 == 0)
                ++res;
        }
        return res;
    }
}
// @lc code=end
