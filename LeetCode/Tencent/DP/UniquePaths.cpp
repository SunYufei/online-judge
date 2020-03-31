#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int uniquePaths(int m, int n) {
        int dp[m + 2][n + 2];
        memset(dp, 0, sizeof(dp));
        dp[m][n - 1] = 1;
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j)
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        return dp[0][0];
    }
};