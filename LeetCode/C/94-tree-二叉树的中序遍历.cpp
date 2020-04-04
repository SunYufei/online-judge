/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
//
// Definition for a binary tree node.
// #include <vector>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        inOrder(root);
        return res;
    }

  private:
    vector<int> res;
    void inOrder(TreeNode *root) {
        if (root == nullptr)
            return;
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
};
// @lc code=end
