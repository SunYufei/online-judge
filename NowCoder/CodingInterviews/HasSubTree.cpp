#include "main.h"

class Solution {
  public:
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        return check(pRoot1, pRoot2) || check(pRoot1->left, pRoot2) ||
               check(pRoot1->right, pRoot2);
    }

  private:
    bool check(TreeNode *p1, TreeNode *p2) {
        if (p2 == nullptr)
            return true;
        if (p1 == nullptr)
            return false;
        if (p1->val != p2->val)
            return check(p1->left, p2) || check(p1->right, p2);
        else
            return check(p1->left, p2->left) && check(p1->right, p2->right);
    }
};