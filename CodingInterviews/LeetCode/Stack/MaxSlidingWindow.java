package Stack;

import java.util.*;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int len = nums.length;
        if (nums == null || k < 1 || len < k)
            return new int[0];
        Deque<Integer> deque = new ArrayDeque<>();
        int[] res = new int[len - k + 1];
        for (int i = 0; i < len; i++) {
            if (!deque.isEmpty() && deque.peekFirst() < i - k + 1)
                deque.removeFirst();
            while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i])
                deque.removeLast();
            deque.offerLast(i);
            if (i >= k - 1)
                res[i - k + 1] = nums[deque.peekFirst()];
        }
        return res;
    }
}