class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    public boolean isBalanced(TreeNode root) {
        return recursion(root) >= 0;
    }

    private int recursion(TreeNode root) {
        if (root == null)
            return 0;
        if (root.left == null && root.right == null)
            return 1;
        int l = recursion(root.left);
        int r = recursion(root.right);
        if (l < 0 || r < 0)
            return -1;
        if (Math.abs(l - r) > 1)
            return -1;
        return Math.max(l, r) + 1;
    }
}
