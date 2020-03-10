import java.util.Arrays;

class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
}

public class MajorityElement {
    public static void main(String[] args) {
        var sol = new Solution();
        System.out.println(sol.majorityElement(new int[] { 1, 2, 3, 2, 2, 2, 5, 4, 2 }));
    }
}