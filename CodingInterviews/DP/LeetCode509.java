package DP;

class Solution {
    public int fib(int n) {
        if (n <= 1)
            return n;
        int ans = 1, a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            ans = (a + b) % 1000000007;
            a = b;
            b = ans;
        }
        return ans;
    }
}