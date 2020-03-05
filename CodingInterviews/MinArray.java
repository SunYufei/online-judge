public class MinArray {
    public static void main(String[] args) {
        int[] nums = { 3, 4, 5, 1, 2 };
        System.out.println(minArray(nums));
    }

    private static int minArray(int[] numbers) {
        int n = numbers.length;
        for (int i = 1; i < n - 1; i++)
            if (numbers[i] < numbers[i - 1])
                return numbers[i];
        return numbers[n - 1];
    }
}