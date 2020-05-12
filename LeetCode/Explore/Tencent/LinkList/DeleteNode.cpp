#include "../../main.h"

class Solution {
  public:
    void deleteNode(ListNode *node) {
        ListNode *p = node;
        while (node->next != nullptr) {
            node->val = node->next->val;
            p = node;
            node = node->next;
        }
        p->next = nullptr;
        delete node;
    }
};