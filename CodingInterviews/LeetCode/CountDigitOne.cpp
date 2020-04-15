class Solution {
  public:
    int countDigitOne(int n) {
        int res = 0;
        long i = 1;
        while (n / i != 0) {
            long high = n / 10 / i;
            long cur = (n / i) % 10;
            long low = n - (n / i) * i;
            if (cur == 0)
                res += high * i;
            else if (cur == 1)
                res += high * i + low + 1;
            else
                res += high * i + i;
            i *= 10;
        }
        return res;
    }
};