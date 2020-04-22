#include "main.h"

class Solution {
  public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
            return root->val == sum;
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};