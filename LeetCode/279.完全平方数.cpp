/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        for (int i = 0; i * i <= n; i++)
            dp[i * i] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j * j < i; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        return dp[n];
    }
};
