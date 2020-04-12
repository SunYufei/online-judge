package Array;

// leetcode 239
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || k < 1 || nums.length < k)
            return new int[0];
        int len = nums.length;
        int[] res = new int[len - k + 1];
        int maxIdx = -1, max = Integer.MIN_VALUE;
        for (int i = 0; i < len - k + 1; i++) {
            if (maxIdx >= i && maxIdx < i + k) {
                if (nums[i + k - 1] > max) {
                    max = nums[i + k - 1];
                    maxIdx = i + k - 1;
                }
            } else {
                max = nums[i];
                for (int j = i; j < i + k; j++)
                    if (max < nums[j]) {
                        max = nums[j];
                        maxIdx = j;
                    }
            }
            res[i] = max;
        }
        return res;
    }
}