/*
 * @lc app=leetcode.cn id=5 lang=java
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
        if (len < 2)
            return s;
        String res = "";
        boolean[][] dp = new boolean[len][len];
        for (int i = len - 1; i >= 0; i--)
            for (int j = i; j < len; j++) {
                dp[i][j] = s.charAt(i) == s.charAt(j) && (j - i < 2 || dp[i + 1][j - 1]);
                if (dp[i][j] && j - i + 1 > res.length())
                    res = s.substring(i, j + 1);
            }
        return res;
    }
}
// @lc code=end
