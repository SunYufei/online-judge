#include "listnode.h"

class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *fast = head->next, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *t = slow->next;
        slow->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(t);
        ListNode *h = new ListNode(0);
        ListNode *res = h;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                h->next = left;
                left = left->next;
            } else {
                h->next = right;
                right = right->next;
            }
            h = h->next;
        }
        h->next = left != nullptr ? left : right;
        ListNode *p = res;
        res = res->next;
        delete p;
        return res;
    }
};