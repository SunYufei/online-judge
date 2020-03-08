class Solution {
    public int minArray(int[] numbers) {
        int n = numbers.length;
        for (int i = 1; i < n - 1; i++)
            if (numbers[i] < numbers[i - 1])
                return numbers[i];
        return numbers[n - 1];
    }
}

public class MinArray {
    public static void main(String[] args) {
        var sol = new Solution();
        int[] nums = { 3, 4, 5, 1, 2 };
        System.out.println(sol.minArray(nums));
    }
}