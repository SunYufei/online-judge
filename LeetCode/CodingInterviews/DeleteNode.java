package LeetCode;

class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        if (head == null)
            return head;
        if (head.val == val)
            return head.next;
        ListNode p = head.next, q = head;
        while (p != null) {
            if (p.val == val)
                q.next = p.next;
            p = p.next;
            q = q.next;
        }
        return head;
    }
}