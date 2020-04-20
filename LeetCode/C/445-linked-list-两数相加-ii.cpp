/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 */
#include "main.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> s1, s2;
        auto p1 = l1, p2 = l2;
        while (p1) {
            s1.push(p1->val);
            p1 = p1->next;
        }
        while (p2) {
            s2.push(p2->val);
            p2 = p2->next;
        }
        int carry = 0;
        ListNode *res = nullptr;
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();
            carry = a + b + carry;
            auto node = new ListNode(carry % 10);
            carry /= 10;
            node->next = res;
            res = node;
        }
        return res;
    }
};
// @lc code=end
