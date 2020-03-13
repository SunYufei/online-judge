/*
 * @lc app=leetcode.cn id=242 lang=java
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;
        int[] table = new int[256];
        for (char i : s.toCharArray())
            table[i]++;
        for (char i : t.toCharArray()) {
            table[i]--;
            if (table[i] < 0)
                return false;
        }
        return true;
    }
}
// @lc code=end
