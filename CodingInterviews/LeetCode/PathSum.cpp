#include "main.h"

class Solution {
  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, sum, path, res);
        return res;
    }

  private:
    void dfs(TreeNode *root, int num, vector<int> &path,
             vector<vector<int>> &res) {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        num -= root->val;
        if (num == 0 && root->left == nullptr && root->right == nullptr)
            res.push_back(path);
        dfs(root->left, num, path, res);
        dfs(root->right, num, path, res);
        path.pop_back();
    }
};