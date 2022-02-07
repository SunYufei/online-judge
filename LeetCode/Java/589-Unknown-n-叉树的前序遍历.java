import java.util.*;

/*
 * @lc app=leetcode.cn id=589 lang=java
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> res = new ArrayList<>();
        pre(root, res);
        return res;
    }

    private void pre(Node root, List<Integer> res) {
        if (root == null)
            return;
        res.add(root.val);
        for (Node child : root.children) {
            pre(child, res);
        }
    }
}
// @lc code=end
