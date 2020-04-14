package LeetCode;

class Solution {
    public int[] exchange(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            while (nums[l] % 2 == 1 && l < r)
                ++l;
            while (nums[r] % 2 == 0 && l < r)
                --r;
            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
        }
        return nums;
    }
}