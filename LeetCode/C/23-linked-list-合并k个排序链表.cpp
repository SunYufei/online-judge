/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = nullptr;
        for (auto l : lists)
            head = merge(head, l);
        return head;
    }

  private:
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1), *p = head, *t;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                t = l1;
                l1 = l1->next;
            } else {
                t = l2;
                l2 = l2->next;
            }
            t->next = p->next;
            p->next = t;
            p = t;
        }
        p->next = l1 != nullptr ? l1 : l2;
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};
// @lc code=end
