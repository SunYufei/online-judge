/*
    剪邮票

    如【图1.jpg】, 有12张连在一起的12生肖的邮票。
    现在你要从中剪下5张来，要求必须是连着的。
    （仅仅连接一个角不算相连）
    比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。

    请你计算，一共有多少种不同的剪取方法。

    请填写表示方案数目的整数。
    注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

    116
*/
#include <cstring>
#include <iostream>
using namespace std;

int num[5];
bool vis[5];
int map[] = {1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14};
int dir[] = {-1, 1, -5, 5};

void dfs(int n) {
    int i, j, t;
    for (i = 0; i < 4; i++) {
        t = num[n] + dir[i];
        if (t < 1 || t > 14 || t == 5 || t == 10)
            continue;
        for (j = 0; j < 5; j++)
            if (!vis[j] && num[j] == t) {
                vis[j] = true;
                dfs(j);
            }
    }
}

int main() {
    int a, b, c, d, e, i;
    bool flag;
    int ans = 0;
    for (a = 0; a < 12; a++)
        for (b = a + 1; b < 12; b++)
            for (c = b + 1; c < 12; c++)
                for (d = c + 1; d < 12; d++)
                    for (e = d + 1; e < 12; e++) {
                        num[0] = map[a];
                        num[1] = map[b];
                        num[2] = map[c];
                        num[3] = map[d];
                        num[4] = map[e];

                        memset(vis, false, sizeof(vis));
                        vis[0] = true;
                        dfs(0);

                        flag = true;
                        for (i = 0; i < 5; i++)
                            if (!vis[i]) {
                                flag = false;
                                break;
                            }
                        if (flag == false)
                            continue;
                        else
                            ans++;
                    }
    cout << ans << endl;
    return 0;
}