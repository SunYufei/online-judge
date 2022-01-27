package LeetCode.Java;

import java.util.*;

/*
 * @lc app=leetcode.cn id=590 lang=java
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start
class Solution {
    public List<Integer> postorder(Node root) {
        List<Integer> res = new ArrayList<>();
        post(root, res);
        return res;
    }

    private void post(Node root, List<Integer> res) {
        if (root == null)
            return;
        for (Node child : root.children) {
            post(child, res);
        }
        res.add(root.val);
    }
}
// @lc code=end
