class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;

        if (n == 0)
            return 0;

        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else {
                while (nums[left] != target)
                    ++left;
                while (nums[right] != target)
                    --right;
                return right - left + 1;
            }
        }

        return 0;
    }
}

public class Search {
    public static void main(String[] args) {
        var sol = new Solution();
        System.out.println(sol.search(new int[] { 5, 7, 7, 8, 8, 10 }, 8));
        System.out.println(sol.search(new int[] { 5, 7, 7, 8, 8, 10 }, 6));
        System.out.println(sol.search(new int[] { 1 }, 1));
    }
}