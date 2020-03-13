/*
 * @lc app=leetcode.cn id=429 lang=java
 *
 * [429] N叉树的层序遍历
 */

// @lc code=start
//
// Definition for a Node.
import java.util.*;

// class Node {
//     public int val;
//     public List<Node> children;

//     public Node() {
//     }

//     public Node(int _val) {
//         val = _val;
//     }

//     public Node(int _val, List<Node> _children) {
//         val = _val;
//         children = _children;
//     }
// };
//

class Solution {

    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res = new ArrayList();

        if (root == null)
            return res;

        var queue = new LinkedList<Node>();
        queue.add(root);

        while (!queue.isEmpty()) {
            var level = new ArrayList<Integer>();
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                var node = queue.poll();
                level.add(node.val);
                queue.addAll(node.children);
            }
            res.add(level);
        }

        return res;
    }

}
// @lc code=end
