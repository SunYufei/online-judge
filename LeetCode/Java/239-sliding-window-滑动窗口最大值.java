
/*
 * @lc app=leetcode.cn id=239 lang=java
 *
 * [239] 滑动窗口最大值
 */
import java.util.*;

// @lc code=start
class Solution {
    ArrayDeque<Integer> deque = new ArrayDeque();
    int[] nums;

    void cleanDeque(int i, int k) {
        if (!deque.isEmpty() && deque.getFirst() == i - k)
            deque.removeFirst();
        while (!deque.isEmpty() && nums[i] > nums[deque.getLast()])
            deque.removeLast();
    }

    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        if (n * k == 0)
            return new int[0];
        if (k == 1)
            return nums;

        this.nums = nums;
        int maxIdx = 0;
        for (int i = 0; i < k; i++) {
            cleanDeque(i, k);
            deque.addLast(i);
            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int[] res = new int[n - k + 1];
        res[0] = nums[maxIdx];

        for (int i = k; i < n; i++) {
            cleanDeque(i, k);
            deque.addLast(i);
            res[i - k + 1] = nums[deque.getFirst()];
        }

        return res;
    }
}
// @lc code=end
