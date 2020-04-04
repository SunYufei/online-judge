/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 */

// @lc code=start
//
// Definition for a Node.
// #include <vector>
// using namespace std;

// class Node {
//   public:
//     int val;
//     vector<Node *> children;

//     Node() {}

//     Node(int _val) { val = _val; }

//     Node(int _val, vector<Node *> _children) {
//         val = _val;
//         children = _children;
//     }
// };

class Solution {
  public:
    vector<int> postorder(Node *root) {
        post(root);
        return res;
    }

  private:
    vector<int> res;
    void post(Node *root) {
        if (root == nullptr)
            return;
        for (auto child : root->children)
            post(child);
        res.push_back(root->val);
    }
};
// @lc code=end
