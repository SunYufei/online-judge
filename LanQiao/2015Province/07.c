/*
    牌型种数

    小明被劫持到X赌城，被迫与其他3人玩牌。
    一副扑克牌（去掉大小王牌，共52张），均匀发给4个人，每个人13张。
    这时，小明脑子里突然冒出一个问题：
    如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢？

    请填写该整数，不要填写任何多余的内容或说明文字。
*/
#include <stdio.h>

// dp[i][j] 当前到第i张牌，总共有j张牌的解的个数
int dp[14][14];

int main() {
    dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
    int a, b, c, d, e, f, g, h, i, j, k, l, m;
    for (i = 2; i <= 13; i++)
        for (k = 0; k <= 13; k++) {
            if (k - 4 >= 0)
                dp[i][k] += dp[i - 1][k - 4];
            if (k - 3 >= 0)
                dp[i][k] += dp[i - 1][k - 3];
            if (k - 2 >= 0)
                dp[i][k] += dp[i - 1][k - 2];
            if (k - 1 >= 0)
                dp[i][k] += dp[i - 1][k - 1];
            dp[i][k] += dp[i - 1][k];
        }
    printf("%d\n", dp[13][13]);
    int ans = 0;
    for (a = 0; a < 5; a++)
        for (b = 0; b < 5; b++)
            for (c = 0; c < 5; c++)
                for (d = 0; d < 5; d++)
                    for (e = 0; e < 5; e++)
                        for (f = 0; f < 5; f++)
                            for (g = 0; g < 5; g++)
                                for (h = 0; h < 5; h++)
                                    for (i = 0; i < 5; i++)
                                        for (j = 0; j < 5; j++)
                                            for (k = 0; k < 5; k++)
                                                for (l = 0; l < 5; l++)
                                                    for (m = 0; m < 5; m++)
                                                        if (a + b + c + d + e +
                                                                f + g + h + i +
                                                                j + k + l + m ==
                                                            13)
                                                            ans++;
    printf("%d\n", ans);
    return 0;
}