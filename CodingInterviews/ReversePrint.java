import java.util.ArrayList;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public int[] reversePrint(ListNode head) {
        var list = new ArrayList<Integer>();
        int n = 0;
        while (head != null) {
            list.add(head.val);
            head = head.next;
            ++n;
        }
        int[] ans = new int[n];
        for (int i = n - 1; i >= 0; --i)
            ans[n - 1 - i] = list.get(i);
        return ans;
    }
}

public class ReversePrint {
    public static void main(String[] args) {

    }
}