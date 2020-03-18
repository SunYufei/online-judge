
/*
 * @lc app=leetcode.cn id=20 lang=java
 *
 * [20] 有效的括号
 */
import java.util.*;

// @lc code=start
class Solution {
    public boolean isValid(String s) {
        var stack = new Stack<Character>();
        for (char c : s.toCharArray()) {
            if (c == '(')
                stack.push(')');
            else if (c == '[')
                stack.push(']');
            else if (c == '{')
                stack.push('}');
            else if (stack.empty() || c != stack.pop())
                return false;
        }
        return stack.empty();
    }
}
// @lc code=end
