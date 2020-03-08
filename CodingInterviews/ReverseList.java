class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode ans = null;
        ListNode t;

        while (head != null) {
            t = head.next;
            head.next = ans;
            ans = head;
            head = t;
        }

        return ans;
    }
}