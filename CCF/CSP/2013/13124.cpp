#include <stdio.h>

const int MAXN = 1002;
const int MOD = 1000000007;

long long dp[MAXN][6];

int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][3] = (dp[i - 1][1] + dp[i - 1][3] * 2) % MOD;
        dp[i][4] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] * 2) % MOD;
        dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5] * 2) % MOD;
    }
    printf("%lld\n", dp[n][5]);
    return 0;
}