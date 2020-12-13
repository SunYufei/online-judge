/*
 * @lc app=leetcode.cn id=144 lang=java
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start

class Solution {
    private List<Integer> res = new ArrayList();

    public List<Integer> preorderTraversal(TreeNode root) {
        _preorder(root);
        return res;
    }

    private void _preorder(TreeNode root) {
        if (root == null)
            return;
        res.add(root.val);
        _preorder(root.left);
        _preorder(root.right);
    }
}
// @lc code=end
