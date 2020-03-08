class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode(0);
        ListNode cur = ans;

        ListNode p1 = l1, p2 = l2;

        while (p1 != null && p2 != null) {
            ListNode t;
            if (p1.val <= p2.val) {
                t = new ListNode(p1.val);
                p1 = p1.next;
            } else {
                t = new ListNode(p2.val);
                p2 = p2.next;
            }
            cur.next = t;
            cur = cur.next;
        }

        while (p1 != null) {
            ListNode t = new ListNode(p1.val);
            cur.next = t;
            cur = cur.next;
            p1 = p1.next;
        }

        while (p2 != null) {
            ListNode t = new ListNode(p2.val);
            cur.next = t;
            cur = cur.next;
            p2 = p2.next;
        }

        return ans.next;
    }
}