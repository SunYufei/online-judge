#include "main.h"

class Solution {
  public:
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
        vector<vector<int>> res;
        vector<int> path;
        recursion(root, expectNumber, path, res);
        return res;
    }

  private:
    void recursion(TreeNode *root, int num, vector<int> &path,
                   vector<vector<int>> &res) {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        num -= root->val;
        if (num == 0 && root->left == nullptr && root->right == nullptr)
            res.push_back(path);
        recursion(root->left, num, path, res);
        recursion(root->right, num, path, res);
        path.pop_back();
    }
};