#include "main.h"

class Solution {
  public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size() == 0 || vin.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(pre[0]);
        for (int i = 0; i < vin.size(); i++)
            if (vin[i] == pre[0]) {
                root->left = reConstructBinaryTree(
                    vector<int>(pre.begin() + 1, pre.begin() + i + 1),
                    vector<int>(vin.begin(), vin.begin() + i));
                root->right = reConstructBinaryTree(
                    vector<int>(pre.begin() + i + 1, pre.end()),
                    vector<int>(vin.begin() + i + 1, vin.end()));
                break;
            }
        return root;
    }
};