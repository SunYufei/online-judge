package LeetCode;

class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode res;
        ListNode p = head;
        for (int i = 0; i < k; i++)
            p = p.next;
        res = head;
        while (p != null) {
            p = p.next;
            res = res.next;
        }
        return res;
    }
}