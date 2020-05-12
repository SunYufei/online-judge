#include "../main.h"

class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        pre(root, res);
        return res;
    }

  private:
    void pre(TreeNode *root, vector<int> &res) {
        if (root == nullptr)
            return;
        res.push_back(root->val);
        if (root->left)
            pre(root->left, res);
        if (root->right)
            pre(root->right, res);
    }
};