/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount <= 0)
            return 0;
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        size_t i, j;
        for (i = 1; i <= amount; i++)
            for (j = 0; j < coins.size(); j++)
                if (coins[j] <= i && dp[i - coins[j]] < INT_MAX)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        if (dp[amount] < INT_MAX)
            return dp[amount];
        else
            return -1;
    }
};
