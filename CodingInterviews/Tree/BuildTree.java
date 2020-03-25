package Tree;

import java.util.*;

// leetcode 105
class Solution {
    int[] preOrder, inOrder;
    int preIndex = 0;
    Map<Integer, Integer> map = new HashMap<>();

    TreeNode build(int left, int right) {
        if (left == right)
            return null;
        int val = preOrder[preIndex++];
        TreeNode root = new TreeNode(val);
        int index = map.get(val);
        root.left = build(left, index);
        root.right = build(index + 1, right);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        this.preOrder = preorder;
        this.inOrder = inorder;
        for (int i = 0; i < inorder.length; i++)
            map.put(inorder[i], i);
        return build(0, inorder.length);
    }
}