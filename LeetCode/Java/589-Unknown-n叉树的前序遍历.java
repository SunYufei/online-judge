import java.util.List;
import java.util.ArrayList;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=589 lang=java
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
class Solution {
    private List<Integer> res = new ArrayList();

    public List<Integer> preorder(Node root) {
        _preorder(root);
        return res;
    }

    private void _preorder(Node root) {
        if (root == null)
            return;
        res.add(root.val);
        for (Node n : root.children)
            _preorder(n);
    }
}
// @lc code=end
