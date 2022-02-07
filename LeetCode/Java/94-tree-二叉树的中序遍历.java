import java.util.*;

/*
 * @lc app=leetcode.cn id=94 lang=java
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        in(root, res);
        return res;
    }

    public void in(TreeNode root, List<Integer> res) {
        if (root == null)
            return;
        in(root.left, res);
        res.add(root.val);
        in(root.right, res);
    }
}
// @lc code=end
