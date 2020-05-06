#include "main.h"

class Solution {
  public:
    RandomListNode *Clone(RandomListNode *pHead) {
        if (pHead == nullptr)
            return nullptr;
        RandomListNode *p = pHead, *q;
        while (p) {
            q = p->next;
            p->next = new RandomListNode(p->label);
            p->next->next = q;
            p = q;
        }
        p = pHead;
        while (true) {
            if (p->random)
                p->next->random = p->random->next;
            if (p->next->next)
                p = p->next->next;
            else
                break;
        }
        p = pHead;
        q = pHead->next;
        RandomListNode *res = pHead->next;
        while (p && q) {
            p->next = q->next;
            p = p->next;
            if (p)
                q->next = p->next;
            else
                break;
            q = q->next;
        }
        return res;
    }
};