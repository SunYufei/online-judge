/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *a = head, *b = head->next;
        ListNode *t = b->next;
        b->next = a;
        a->next = swapPairs(t);
        return b;
    }
};
// @lc code=end
