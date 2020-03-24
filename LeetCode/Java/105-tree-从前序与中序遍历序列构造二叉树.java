import java.util.Map;

/*
 * @lc app=leetcode.cn id=105 lang=java
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    int preIndex = 0;
    int[] preorder;
    int[] inorder;
    Map<Integer, Integer> idxMap = new HashMap();

    TreeNode recursion(int left, int right) {
        if (left == right)
            return null;
        int rootVal = preorder[preIndex++];
        TreeNode root = new TreeNode(rootVal);
        int index = idxMap.get(rootVal);
        root.left = recursion(left, index);
        root.right = recursion(index + 1, right);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        this.preorder = preorder;
        this.inorder = inorder;
        int idx = 0;
        for (var val : inorder)
            idxMap.put(val, idx++);
        return recursion(0, inorder.length);
    }
}
// @lc code=end
