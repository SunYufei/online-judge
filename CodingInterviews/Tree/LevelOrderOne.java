package Tree;

import java.util.*;

class Solution {
    public int[] levelOrder(TreeNode root) {
        if (root == null)
            return new int[0];
        List<Integer> res = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode t = queue.poll();
                res.add(t.val);
                if (t.left != null)
                    queue.add(t.left);
                if (t.right != null)
                    queue.add(t.right);
            }
        }
        return res.stream().mapToInt(Integer::valueOf).toArray();
    }
}