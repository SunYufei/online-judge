package LeetCode;

class Solution {
    public boolean isBalanced(TreeNode root) {
        return diff(root) != -1;
    }

    int diff(TreeNode root) {
        if (root == null)
            return 0;
        int left = diff(root.left);
        if (left == -1)
            return -1;
        int right = diff(root.right);
        if (right == -1)
            return -1;
        return Math.abs(left - right) < 2 ? Math.max(left, right) + 1 : -1;
    }
}