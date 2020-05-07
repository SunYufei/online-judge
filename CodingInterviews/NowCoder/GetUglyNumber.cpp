#include "main.h"

class Solution {
  public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;
        vector<int> dp(index);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < index; ++i) {
            dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
            if (dp[i] == dp[p2] * 2)
                ++p2;
            if (dp[i] == dp[p3] * 3)
                ++p3;
            if (dp[i] == dp[p5] * 5)
                ++p5;
        }
        return dp[index - 1];
    }
};