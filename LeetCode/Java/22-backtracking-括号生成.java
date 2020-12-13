/*
 * @lc app=leetcode.cn id=22 lang=java
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
    private List<String> res;

    public List<String> generateParenthesis(int n) {
        res = new ArrayList<>();
        generate(0, 0, n, "");
        return res;
    }

    private void generate(int left, int right, int n, String s) {
        if (left == n && right == n) {
            res.add(s);
            return;
        }

        if (left < n)
            generate(left + 1, right, n, s + "(");

        if (left > right)
            generate(left, right + 1, n, s + ")");
    }
}
// @lc code=end
