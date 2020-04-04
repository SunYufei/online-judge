/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 */

// @lc code=start
//
// Definition for singly-linked list.
// #include <bits/stdc++.h>
// using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto head : lists)
            while (head) {
                pq.push(head);
                head = head->next;
            }
        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        while (!pq.empty()) {
            ListNode *t = pq.top();
            pq.pop();
            t->next = p->next;
            p->next = t;
            p = t;
        }
        p = head;
        head = head->next;
        delete p;
        return head;
    }

  private:
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
    };
};
// @lc code=end
