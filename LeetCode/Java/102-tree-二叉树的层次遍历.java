/*
 * @lc app=leetcode.cn id=102 lang=java
 *
 * [102] 二叉树的层次遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    private List<List<Integer>> res = new ArrayList();

    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null)
            return res;
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode node, int level) {
        if (res.size() == level)
            res.add(new ArrayList<Integer>());

        res.get(level).add(node.val);

        if (node.left != null)
            dfs(node.left, level + 1);
        if (node.right != null)
            dfs(node.right, level + 1);
    }
}
// @lc code=end
