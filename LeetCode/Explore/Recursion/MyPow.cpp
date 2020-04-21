class Solution {
  public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        if (x == 1 || n == 0)
            return 1.0;
        long t = n;
        if (t < 0) {
            x = 1.0 / x;
            t = -t;
        }
        double res = 1.0;
        while (t) {
            if (t & 1)
                res *= x;
            x *= x;
            t >>= 1;
        }
        return res;
    }
};