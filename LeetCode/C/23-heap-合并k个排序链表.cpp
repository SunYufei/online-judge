/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto list : lists)
            while (list) {
                pq.push(list);
                list = list->next;
            }
        ListNode head(-1), *p = &head, *t;
        while (!pq.empty()) {
            t = pq.top();
            pq.pop();
            t->next = p->next;
            p->next = t;
            p = p->next;
        }
        return head.next;
    }

  private:
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
    };
};
// @lc code=end
