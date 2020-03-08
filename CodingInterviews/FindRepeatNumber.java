import java.util.HashSet;
import java.util.Set;

class Solution {
    public int findRepeatNumber(int[] nums) {
        int repeat = -1;
        Set<Integer> set = new HashSet<Integer>();
        for (int num : nums) {
            if (!set.add(num)) {
                repeat = num;
                break;
            }
        }
        return repeat;
    }
}

public class FindRepeatNumber {
    public static void main(String[] args) {
        int[] nums = { 2, 3, 1, 0, 2, 5, 3 };
        var sol = new Solution();
        System.out.println(sol.findRepeatNumber(nums));
    }
}
