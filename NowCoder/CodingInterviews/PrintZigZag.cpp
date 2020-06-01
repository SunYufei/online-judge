#include "main.h"

class Solution {
  public:
    vector<vector<int>> Print(TreeNode *pRoot) {
        if (pRoot == nullptr)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(pRoot);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> l;
            while (size--) {
                auto t = q.front();
                l.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                q.pop();
            }
            if ((level & 1) == 1)
                reverse(l.begin(), l.end());
            res.push_back(l);
            ++level;
        }
        return res;
    }
};