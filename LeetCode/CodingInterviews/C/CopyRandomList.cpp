#include "main.h"

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node *p = head, *q;
        while (p) {
            q = p->next;
            p->next = new Node(p->val);
            p->next->next = q;
            p = q;
        }
        p = head;
        while (true) {
            if (p->random)
                p->next->random = p->random->next;
            if (p->next->next)
                p = p->next->next;
            else
                break;
        }
        p = head;
        q = head->next;
        Node* res = head->next;
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