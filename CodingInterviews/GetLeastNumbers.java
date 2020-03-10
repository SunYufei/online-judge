import java.util.Arrays;

class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0)
            return new int[0];
        Arrays.sort(arr);
        return Arrays.copyOf(arr, k);
    }
}

public class GetLeastNumbers {
    public static void main(String[] args) {
        var sol = new Solution();
        System.out.print(sol.getLeastNumbers(new int[] { 3, 2, 1 }, 2));
    }
}