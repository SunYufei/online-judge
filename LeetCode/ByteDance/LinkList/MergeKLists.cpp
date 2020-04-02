#include "listnode.h"

class Solution {
  public:
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return nullptr;
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto list : lists)
            while (list != nullptr) {
                ListNode *t = list;
                list = list->next;
                pq.push(t);
            }
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (!pq.empty()) {
            ListNode *t = pq.top();
            pq.pop();
            t->next = p->next;
            p->next = t;
            p = p->next;
        }
        p->next = nullptr;
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};