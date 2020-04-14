#include "main.h"

class Solution {
  public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> res;
        while (head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> res;
        traverse(head, res);
        return res;
    }

    void traverse(ListNode *node, vector<int> &res) {
        if (node == nullptr)
            return;
        traverse(node->next, res);
        res.emplace_back(node->val);
    }
};