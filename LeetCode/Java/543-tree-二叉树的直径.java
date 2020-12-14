/*
 * @lc app=leetcode.cn id=543 lang=java
 *
 * [543] 二叉树的直径
 */

// @lc code=start
class Solution {
    private int ans;

    public int diameterOfBinaryTree(TreeNode root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }

    private int depth(TreeNode node) {
        if (node == null)
            return 0;
        int l = depth(node.left);
        int r = depth(node.right);
        ans = Math.max(ans, l + r + 1);
        return Math.max(l, r) + 1;
    }
}
// @lc code=end
