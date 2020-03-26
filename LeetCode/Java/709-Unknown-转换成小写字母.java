/*
 * @lc app=leetcode.cn id=709 lang=java
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution {
    public String toLowerCase(String str) {
        var builder = new StringBuilder();
        for (char c : str.toCharArray()) {
            if (c >= 'A' && c <= 'Z')
                builder.append((char) (c + 'a' - 'A'));
            else
                builder.append(c);
        }
        return builder.toString();
    }
}
// @lc code=end
