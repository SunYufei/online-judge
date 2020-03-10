class Solution {
    public int[] printNumbers(int n) {
        int max = (int) Math.pow(10, n);
        int[] res = new int[max - 1];
        for (int i = 1; i < max; i++)
            res[i - 1] = i;
        return res;
    }
}

public class PrintNumbers {
    public static void main(String[] args) {

    }
}