package Tree;

import java.util.*;

class Solution {
    int[] preOrder, inOrder;
    int preIndex = 0;
    Map<Integer, Integer> map = new HashMap<>();

    TreeNode build(int left, int right) {
        if (left == right)
            return null;
        int rootVal = preOrder[preIndex++];
        TreeNode root = new TreeNode(rootVal);
        int index = map.get(rootVal);
        root.left = build(left, index);
        root.right = build(index + 1, right);
        return root;
    }

    TreeNode buildTree(int[] preorder, int[] inorder) {
        this.preOrder = preorder;
        this.inOrder = inorder;
        for (int i = 0; i < inorder.length; i++)
            map.put(inorder[i], i);
        return build(0, inorder.length);
    }
}