package Heap;

import java.util.PriorityQueue;

// leetcode 239
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k <= 0)
            return new int[0];
        PriorityQueue<Integer> heap = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < k; i++)
            heap.add(nums[i]);
        int[] res = new int[nums.length - k + 1];
        int j = 0;
        res[j++] = heap.peek();
        for (int i = k; i < nums.length; i++) {
            heap.remove(nums[i - k]);
            heap.add(nums[i]);
            res[j++] = heap.peek();
        }
        return res;
    }
}