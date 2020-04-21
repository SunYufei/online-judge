class Solution {
  public:
    int fib(int N) {
        if (N < 2)
            return N;
        int p = 0, c = 1;
        for (int i = 2; i <= N; i++) {
            c = p + c;
            p = c - p;
        }
        return c;
    }
};