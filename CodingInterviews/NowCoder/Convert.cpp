#include "main.h"

class Solution {
  public:
    TreeNode *Convert(TreeNode *pRootOfTree) {
        if (pRootOfTree == nullptr)
            return nullptr;
        Convert(pRootOfTree->right);
        if (pre == nullptr)
            pre = pRootOfTree;
        else {
            pRootOfTree->right = pre;
            pre->left = pRootOfTree;
            pre = pRootOfTree;
        }
        Convert(pRootOfTree->left);
        return pre;
    }

  private:
    TreeNode *pre = nullptr;
};