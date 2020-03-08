class Solution {
    public int fib(int n) {
        if (n <= 1)
            return n;
        long a = 0, b = 1;
        long ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = (a + b) % 1000000007;
            a = b;
            b = ans;
        }
        return (int) ans;
    }
}

public class Fibonacci {
    public static void main(String[] args) {
        var sol = new Solution();
        System.out.println(sol.fib(100));
    }
}
