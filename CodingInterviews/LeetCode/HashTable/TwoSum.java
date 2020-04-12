package HashTable;

import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (set.contains(target - num))
                return new int[] { target - num, num };
            set.add(num);
        }
        return new int[0];
    }
}