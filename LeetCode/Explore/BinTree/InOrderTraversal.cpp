#include "main.h"

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        in(root, res);
        return res;
    }

  private:
    void in(TreeNode *root, vector<int> &res) {
        if (root == nullptr)
            return;
        if (root->left)
            in(root->left, res);
        res.push_back(root->val);
        if (root->right)
            in(root->right, res);
    }
};