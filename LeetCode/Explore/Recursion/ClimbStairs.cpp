class Solution {
  public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        int p = 1, c = 2;
        for (int i = 3; i <= n; i++) {
            c = p + c;
            p = c - p;
        }
        return c;
    }
};