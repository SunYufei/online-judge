package LeetCode;

import java.util.*;

class Solution {
    public int kthLargest(TreeNode root, int k) {
        var res = new ArrayList<Integer>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
        while (cur != null || !stack.empty()) {
            while (cur != null) {
                stack.push(cur);
                cur = cur.right;
            }
            cur = stack.pop();
            res.add(cur.val);
            cur = cur.left;
        }
        return res.get(k - 1);
    }
}