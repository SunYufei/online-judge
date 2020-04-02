#include "listnode.h"

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode *> st;
        ListNode *p = head;
        while (p) {
            if (st.count(p))
                return p;
            st.insert(p);
            p = p->next;
        }
        return nullptr;
    }
};