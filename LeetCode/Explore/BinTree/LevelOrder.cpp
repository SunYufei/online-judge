#include "../main.h"

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            res.push_back({});
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                res.back().push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }
        }
        return res;
    }
};