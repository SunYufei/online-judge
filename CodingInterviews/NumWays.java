public class NumWays {
    public static void main(String[] args) {
        System.out.println(numWays(2));
        System.out.println(numWays(7));
    }

    private static int numWays(int n) {
        if (n == 0)
            return 1;
        if (n <= 2)
            return n;
        long a = 1, b = 2, ans = 0;
        for (int i = 3; i <= n; i++) {
            ans = (a + b) % 1000000007;
            a = b;
            b = ans;
        }
        return (int) ans;
    }
}