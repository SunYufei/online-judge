import java.util.*;
/*
 * @lc app=leetcode.cn id=515 lang=java
 *
 * [515] 在每个树行中找最大值
 */

// @lc code=start
class Solution {
    public List<Integer> largestValues(TreeNode root) {
        var res = new ArrayList<Integer>();

        if (root == null)
            return res;

        Queue<TreeNode> q = new LinkedList();
        q.add(root);

        while (!q.isEmpty()) {
            int size = q.size();
            int max = Integer.MIN_VALUE;
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                max = Math.max(max, node.val);
                if (node.left != null)
                    q.add(node.left);
                if (node.right != null)
                    q.add(node.right);
            }
            res.add(max);
        }

        return res;
    }
}
// @lc code=end
