#include <bits/stdc++.h>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x)
        : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
  public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode) {
        if (pNode->right != nullptr) {
            TreeLinkNode *pRight = pNode->right;
            while (pRight->left != nullptr)
                pRight = pRight->left;
            return pRight;
        }
        if (pNode->next != nullptr && pNode->next->left == pNode)
            return pNode->next;

        if (pNode->next != nullptr) {
            TreeLinkNode *pNext = pNode->next;
            while (pNext->next != nullptr && pNext->next->right == pNext)
                pNext = pNext->next;
            return pNext->next;
        }
        return nullptr;
    }
};