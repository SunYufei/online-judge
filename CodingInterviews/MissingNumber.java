public class MissingNumber {
    public static void main(String[] args) {
        System.out.println(missingNumber(new int[] { 0, 1, 3 }));
        System.out.println(missingNumber(new int[] { 0, 1, 2, 3, 4, 5, 6, 7, 9 }));
    }

    private static int missingNumber(int[] nums) {
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