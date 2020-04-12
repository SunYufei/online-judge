class Solution {
  public:
    double Power(double base, int exponent) {
        if (exponent == 0)
            return 1.0;
        if (exponent < 0) {
            base = 1.0 / base;
            exponent = -exponent;
        }
        double res = 1.0;
        while (exponent > 0) {
            if (exponent & 1 == 1)
                res *= base;
            base *= base;
            exponent >>= 1;
        }
        return res;
    }
};