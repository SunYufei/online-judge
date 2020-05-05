#include "main.h"

class Solution {
  public:
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, expectNumber, path, res);
        return res;
    }

  private:
    void dfs(TreeNode *root, int num, vector<int> &path,
             vector<vector<int>> &res) {}
};