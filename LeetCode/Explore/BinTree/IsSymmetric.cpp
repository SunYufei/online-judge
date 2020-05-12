#include "../main.h"

class Solution {
  public:
    bool isSymmetric(TreeNode *root) { return check(root, root); }

  private:
    bool check(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        if (t1 == nullptr || t2 == nullptr)
            return false;
        return t1->val == t2->val && check(t1->left, t2->right) &&
               check(t2->right, t1->left);
    }
};