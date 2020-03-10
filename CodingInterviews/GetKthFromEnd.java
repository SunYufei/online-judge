class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode res;
        ListNode p = head;
        while (p != null && k > 0) {
            p = p.next;
            --k;
        }
        if (k > 0)
            return null;
        res = head;
        while (p != null) {
            p = p.next;
            res = res.next;
        }
        return res;
    }
}
