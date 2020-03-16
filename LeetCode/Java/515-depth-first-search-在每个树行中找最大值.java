import java.awt.List;

/*
 * @lc app=leetcode.cn id=515 lang=java
 *
 * [515] 在每个树行中找最大值
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    private List<Integer> res = new ArrayList();

    public List<Integer> largestValues(TreeNode root) {
        if (root != null)
            dfs(root, 0);
        return res;
    }

    private void dfs(TreeNode root, int level) {
        if (level == res.size())
            res.add(Integer.MIN_VALUE);
        if (root.val > res.get(level))
            res.set(level, root.val);
        if (root.left != null)
            dfs(root.left, level + 1);
        if (root.right != null)
            dfs(root.right, level + 1);
    }
}
// @lc code=end
