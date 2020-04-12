#include "main.h"

class Solution {
  public:
    vector<vector<int>> Print(TreeNode *pRoot) {
        vector<vector<int>> res;
        if (pRoot == nullptr)
            return res;
        queue<TreeNode *> q;
        q.push(pRoot);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode *t = q.front();
                level.push_back(t->val);
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
                q.pop();
            }
            res.push_back(level);
        }
        return res;
    }
};