
/*
 * @lc app=leetcode.cn id=1160 lang=java
 *
 * [1160] 拼写单词
 */
import java.util.*;

// @lc code=start
class Solution {
    public int countCharacters(String[] words, String chars) {
        int res = 0;

        char[] cs = new char[26];
        for (char c : chars.toCharArray())
            ++cs[c - 'a'];

        for (String s : words) {
            boolean flag = true;
            if (chars.length() < s.length())
                flag = false;
            else {
                char[] t = new char[26];
                for (char c : s.toCharArray()) {
                    ++t[c - 'a'];
                    if (t[c - 'a'] > cs[c - 'a']) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
                res += s.length();
        }

        return res;
    }
}
// @lc code=end
