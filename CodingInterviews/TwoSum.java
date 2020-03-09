import java.util.HashSet;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        var set = new HashSet<Integer>();
        for (int i : nums) {
            if (set.contains(target - i))
                return new int[] { target - i, i };
            set.add(i);
        }
        return null;
    }
}

public class TwoSum {
    public static void main(String[] args) {
        var sol = new Solution();
        System.out.println(sol.twoSum(new int[] { 2, 7, 11, 5 }, 9));
        System.out.println(sol.twoSum(new int[] { 10, 26, 30, 31, 47, 60 }, 40));
    }
}