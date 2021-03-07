#include "main.h"

class Solution {
   public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
            return false;
        return check(A, B) || isSubStructure(A->left, B) ||
               isSubStructure(A->right, B);
    }

    bool check(TreeNode* t1, TreeNode* t2) {
        if (t2 == nullptr)
            return true;
        if (t1 == nullptr || t1->val != t2->val)
            return false;
        return check(t1->left, t2->left) && check(t1->right, t2->right);
    }
};