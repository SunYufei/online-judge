
/*
 * @lc app=leetcode.cn id=22 lang=java
 *
 * [22] 括号生成
 */
import java.util.*;

// @lc code=start
class Solution {
    public List<String> generateParenthesis(int n) {
        var res = new ArrayList<String>();
        if (n != 0)
            dfs("", n, n, res);
        return res;
    }

    private void dfs(String s, int left, int right, List<String> res) {
        if (left == 0 && right == 0) {
            res.add(s);
            return;
        }

        if (left > right)
            return;

        if (left > 0)
            dfs(s + '(', left - 1, right, res);
        if (right > 0)
            dfs(s + ')', left, right - 1, res);
    }
}
// @lc code=end
