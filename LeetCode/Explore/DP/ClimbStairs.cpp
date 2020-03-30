class Solution {
  public:
    int climbStairs(int n) {
        if (n <= 1)
            return n;
        int a = 1, b = 1, ans = 2;
        for (int i = 2; i <= n; i++) {
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};