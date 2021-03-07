#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int arr[3][3];  // 1 Alice && 2 Bob

bool judge(int v) {                //判断玩家v是否获胜
    for (int i = 0; i < 3; i++) {  //行列
        if (arr[i][0] == v && arr[i][1] == v && arr[i][2] == v)
            return true;
        if (arr[0][i] == v && arr[1][i] == v && arr[2][i] == v)
            return true;
    }
    //对角线
    if (arr[0][0] == v && arr[1][1] == v && arr[2][2] == v)
        return true;
    if (arr[0][2] == v && arr[1][1] == v && arr[2][0] == v)
        return true;
    return false;
}

int dfs(int v) {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {  //计算空格数
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == 0)
                cnt++;
        }
    }

    if (v == 1 && judge(2))
        return -cnt - 1;  //轮到Alice，但当前局面Bob已经获胜
    if (v == 2 && judge(1))
        return cnt + 1;  //轮到Bob，但当前局面Alice已经获胜
    if (cnt == 0)
        return 0;             //平局
    int mn = INF, mx = -INF;  //初始化最大值和最小值
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = v;  //填充空格
                if (v == 1)
                    mx = max(mx, dfs(2));  //计算所有可能局面中的最大得分
                if (v == 2)
                    mn = min(mn, dfs(1));
                arr[i][j] = 0;  //恢复当前局面
            }
        }
    }

    //当前局面无获胜
    if (v == 1)
        return mx;
    if (v == 2)
        return mn;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        printf("%d\n", dfs(1));
    }
    return 0;
}