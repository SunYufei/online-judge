class Solution {
  public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        int l = 2, r = x / 2;
        while (l <= r) {
            long m = (l + r) >> 1;
            long t = m * m;
            if (t > x)
                r = m - 1;
            else if (t < x)
                l = m + 1;
            else
                return m;
        }
        return r;
    }
};

int main() {}