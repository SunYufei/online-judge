class Solution {
  public:
    int jumpFloor(int number) {
        if (number <= 2)
            return number;
        int ans = 2, a = 1, b = 2;
        for (int i = 3; i <= number; i++) {
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};