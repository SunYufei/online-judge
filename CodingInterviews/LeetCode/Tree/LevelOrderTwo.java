package Tree;

import java.util.*;

// leetcode 102

class Solution {
    List<List<Integer>> res;

    public List<List<Integer>> levelOrder(TreeNode root) {
        res = new ArrayList<>();
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode root, int level) {
        if (root == null)
            return;
        if (res.size() == level)
            res.add(new ArrayList<>());
        res.get(level).add(root.val);
        if (root.left != null)
            dfs(root.left, level + 1);
        if (root.right != null)
            dfs(root.right, level + 1);
    }
}