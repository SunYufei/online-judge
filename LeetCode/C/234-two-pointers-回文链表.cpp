/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast)
            slow = slow->next;
        ListNode *left = head, *right = reverse(slow);
        while (right) {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

  private:
    ListNode *reverse(ListNode *head) {
        ListNode *p = nullptr, *c = head, *t;
        while (c) {
            t = c->next;
            c->next = p;
            p = c;
            c = t;
        }
        return p;
    }
};
// @lc code=end
