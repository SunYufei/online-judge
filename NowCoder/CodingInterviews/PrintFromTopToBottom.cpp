#include "main.h"

class Solution {
  public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *t = q.front();
                res.push_back(t->val);
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
                q.pop();
            }
        }
        return res;
    }
};