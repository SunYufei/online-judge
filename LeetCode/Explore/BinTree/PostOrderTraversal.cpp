#include "main.h"

class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        post(root, res);
        return res;
    }

  private:
    void post(TreeNode *root, vector<int> &res) {
        if (root == nullptr)
            return;
        if (root->left)
            post(root->left, res);
        if (root->right)
            post(root->right, res);
        res.push_back(root->val);
    }
};