#include "treenode.h"

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        int index = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode *t = q.front();
                q.pop();
                level.push_back(t->val);
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
            }
            if (++index % 2 == 0)
                reverse(level.begin(), level.end());
            res.push_back(level);
        }
        return res;
    }
};