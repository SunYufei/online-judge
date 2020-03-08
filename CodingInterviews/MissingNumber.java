class Solution {
    public int missingNumber(int[] nums) {
        int l = 0, r = nums.length;

        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] != m)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
}

public class MissingNumber {
    public static void main(String[] args) {
        var sol = new Solution();
        System.out.println(sol.missingNumber(new int[] { 0, 1, 3 }));
        System.out.println(sol.missingNumber(new int[] { 0, 1, 2, 3, 4, 5, 6, 7, 9 }));
    }
}
