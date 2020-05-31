#include "main.h"

class Solution {
  public:
    bool isSymmetrical(TreeNode *pRoot) { return check(pRoot, pRoot); }

  private:
    bool check(TreeNode *a, TreeNode *b) {
        if (a == nullptr && b == nullptr)
            return true;
        if (a == nullptr || b == nullptr)
            return false;
        return a->val == b->val && check(a->left, b->right) &&
               check(a->right, b->left);
    }
};