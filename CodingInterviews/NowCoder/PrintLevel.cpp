#include "main.h"

class Solution {
  public:
    vector<vector<int>> Print(TreeNode *pRoot) {
        if (pRoot == nullptr)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(pRoot);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            while (size--) {
                auto t = q.front();
                level.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                q.pop();
            }
            res.push_back(level);
        }
        return res;
    }
};