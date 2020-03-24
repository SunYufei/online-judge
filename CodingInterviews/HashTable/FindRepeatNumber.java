package HashTable;

import java.util.HashSet;
import java.util.Set;

public class FindRepeatNumber {
    int findRepeatNumber(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums)
            if (!set.add(num))
                return num;
        return nums[0];
    }
}