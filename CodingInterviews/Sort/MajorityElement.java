package Sort;

import java.util.Arrays;

// leetcode 169
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
}