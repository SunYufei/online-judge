class Solution {
    public boolean isSymmetric(TreeNode root) {
        return root == null ? true : recursion(root.left, root.right);
    }

    private boolean recursion(TreeNode left, TreeNode right) {
        if (left == null && right == null)
            return true;
        if (left == null || right == null || left.val != right.val)
            return false;
        return recursion(left.left, right.right) && recursion(left.right, right.left);
    }
}