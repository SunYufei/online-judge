public class ReverseList {
    public static void main(String[] args) {

    }

    private static ListNode reverseList(ListNode head) {
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

    private class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
}