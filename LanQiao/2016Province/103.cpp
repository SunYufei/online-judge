/*
    搭积木

    小明最近喜欢搭数字积木，
    一共有10块积木，每个积木上有一个数字，0~9。

    搭积木规则：
    每个积木放到其它两个积木的上面，并且一定比下面的两个积木数字小。
    最后搭成4层的金字塔形，必须用完所有的积木。

    下面是两种合格的搭法：

       0
      1 2
     3 4 5
    6 7 8 9

       0
      3 1
     7 5 2
    9 8 6 4

    请你计算这样的搭法一共有多少种？

    请填表示总数目的数字。
    注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

    768
    注意：next_permutation函数不会生成原始数组的排列
*/
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ans = 0;
    while (next_permutation(a, a + 10)) {
        if (a[0] < a[1] && a[0] < a[2]) {
            if (a[1] < a[3] && a[1] < a[4]) {
                if (a[2] < a[4] && a[2] < a[5]) {
                    if (a[3] < a[6] && a[3] < a[7]) {
                        if (a[4] < a[7] && a[4] < a[8]) {
                            if (a[5] < a[8] && a[5] < a[9])
                                ans++;
                            else
                                continue;
                        } else
                            continue;
                    } else
                        continue;
                } else
                    continue;
            } else
                continue;
        } else
            continue;
    }
    cout << ans << endl;
    return 0;
}