package LeetCode;

import java.util.Set;
import java.util.HashSet;

class Solution {
    public boolean isStraight(int[] nums) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        Set<Integer> set = new HashSet<>();
        for (int num : nums)
            if (num != 0) {
                if (set.contains(num))
                    return false;
                set.add(num);
                max = Math.max(max, num);
                min = Math.min(min, num);
            }
        return max - min < 5;
    }
}