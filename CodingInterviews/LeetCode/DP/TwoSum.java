package DP;

class Solution {
    public double[] twoSum(int n) {
        int[][] dp = new int[n + 1][6 * n + 1];
        for (int i = 1; i <= 6; i++)
            dp[1][i] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = i; j <= 6 * i; j++)
                for (int c = 1; c <= 6; c++)
                    if (j - c > 0)
                        dp[i][j] += dp[i - 1][j - c];
        double all = Math.pow(6, n);
        double[] res = new double[5 * n + 1];
        for (int i = n; i <= 6 * n; i++)
            res[i - n] = (double) dp[n][i] / all;
        return res;
    }
}