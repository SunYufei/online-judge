class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        if (head == null)
            return head;

        if (head.val == val)
            head = head.next;

        ListNode pre = head, cur = head.next;

        while (cur != null) {
            if (cur.val == val)
                pre.next = cur.next;
            cur = cur.next;
            pre = pre.next;
        }

        return head;
    }
}
