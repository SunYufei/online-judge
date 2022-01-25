package LeetCode.Java.p144;

import java.util.ArrayList;
import java.util.List;
import LeetCode.Java.node.TreeNode;
/*
 * @lc app=leetcode.cn id=144 lang=java
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        pre(root, res);
        return res;
    }

    private void pre(TreeNode root, List<Integer> res) {
        if (root == null)
            return;
        res.add(root.val);
        pre(root.left, res);
        pre(root.right, res);
    }
}
// @lc code=end
