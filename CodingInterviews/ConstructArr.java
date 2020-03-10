import java.util.Arrays;

class Solution {
    public int[] constructArr(int[] a) {
        int n = a.length;

        if (n == 0)
            return new int[0];

        int[] res = new int[n];

        int t = 1;
        for (int i = 0; i < n; i++) {
            res[i] = t;
            t *= a[i];
        }

        t = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= t;
            t *= a[i];
        }

        return res;
    }
}

public class ConstructArr {
    public static void main(String[] args) {
        var sol = new Solution();
        System.out.print(Arrays.toString(sol.constructArr(new int[] { 1, 2, 3, 4, 5 })));
    }
}