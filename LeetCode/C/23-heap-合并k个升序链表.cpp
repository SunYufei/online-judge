/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */
#include "main.h"
// @lc code=start
class Solution {
public:
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto list : lists) {
            while (list) {
                pq.push(list);
                list = list->next;
            }
        }
        ListNode res(-1), *p = &res;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            p->next = t;
            p = p->next;
        }
        p->next = nullptr;
        return res.next;
    }
};
// @lc code=end

