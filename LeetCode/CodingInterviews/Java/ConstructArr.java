package LeetCode;

class Solution {
    public int[] constructArr(int[] a) {
        if (a == null || a.length == 0)
            return new int[0];
        int n = a.length;
        int[] b = new int[n];
        int t = 1;
        for (int i = 0; i < n; i++) {
            b[i] = t;
            t *= a[i];
        }
        t = 1;
        for (int i = n - 1; i >= 0; i--) {
            b[i] *= t;
            t *= a[i];
        }
        return b;
    }
}