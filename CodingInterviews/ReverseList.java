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