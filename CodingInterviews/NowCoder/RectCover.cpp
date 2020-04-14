class Solution {
  public:
    int rectCover(int number) {
        if (number <= 2)
            return number;
        int p = 1, c = 2;
        for (int i = 3; i <= number; i++) {
            c = p + c;
            p = c - p;
        }
        return c;
    }
};