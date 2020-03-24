package DP;

class NumWays {
    int numWays(int n) {
        if (n <= 1)
            return 1;
        int ans = 2, a = 1, b = 1;
        for (int i = 2; i <= n; i++) {
            ans = (a + b) % 1000000007;
            a = b;
            b = ans;
        }
        return ans;
    }
}