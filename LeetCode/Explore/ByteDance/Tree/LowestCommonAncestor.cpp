#include "../../main.h"

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        if (left && right)
            return root;
        return nullptr;
    }
};