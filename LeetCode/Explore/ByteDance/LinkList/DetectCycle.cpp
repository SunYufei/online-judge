#include "listnode.h"

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> st;
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