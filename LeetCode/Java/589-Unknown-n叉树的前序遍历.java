import java.util.List;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=589 lang=java
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
//
// Definition for a Node.
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
    private List<Integer> res = new ArrayList();

    public List<Integer> preorder(Node root) {
        _preorder(root);
        return res;
    }

    private void _preorder(Node root) {
        if (root == null)
            return;
        res.add(root.val);
        for (Node n : root.children)
            _preorder(n);
    }
}
// @lc code=end
