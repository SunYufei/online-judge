import java.util.*;

/*
 * @lc app=leetcode.cn id=102 lang=java
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        level(root, 0, res);
        return res;
    }

    private void level(TreeNode root, int step, List<List<Integer>> res) {
        if (root == null)
            return;
        if (res.size() == step)
            res.add(new ArrayList<>());
        res.get(step).add(root.val);
        level(root.left, step + 1, res);
        level(root.right, step + 1, res);
    }
}
// @lc code=end
