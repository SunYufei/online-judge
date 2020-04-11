/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int superEggDrop(int K, int N) {
        vector<int> dp(N + 1);
        for (int i = 0; i <= N; i++)
            dp[i] = i;
        for (int k = 2; k <= K; k++) {
            vector<int> t(N + 1);
            int x = 1;
            t[0] = 0;
            for (int n = 1; n <= N; n++) {
                while (x < n &&
                       max(dp[x - 1], t[n - x]) >= max(dp[x], t[n - x - 1]))
                    ++x;
                t[n] = 1 + max(dp[x - 1], t[n - x]);
            }
            for (int n = 1; n <= N; n++)
                dp[n] = t[n];
        }
        return dp[N];
    }
};
// @lc code=end
