/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto p1 = l1, p2 = l2;
        ListNode res(-1), *p = &res;
        int carry = 0;
        while (p1 || p2 || carry != 0) {
            int a = p1 ? p1->val : 0;
            int b = p2 ? p2->val : 0;
            carry += a + b;
            p->next = new ListNode(carry % 10);
            carry /= 10;
            if (p1)
                p1 = p1->next;
            if (p2)
                p2 = p2->next;
            p = p->next;
        }
        return res.next;
    }
};
// @lc code=end
