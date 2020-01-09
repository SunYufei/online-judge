/*
    方格填数

    如下的10个格子
       +--+--+--+
       | 0| 1| 2|
    +--+--+--+--+
    | 3| 4| 5| 6|
    +--+--+--+--+
    | 7| 8| 9|
    +--+--+--+

    （如果显示有问题，也可以参看【图1.jpg】）

    填入0~9的数字。要求：连续的两个数字不能相邻。
    （左右、上下、对角都算相邻）

    一共有多少种可能的填数方案？

    请填写表示方案数目的整数。
    注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

    1580
*/

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

bool check() {
    if (abs(a[0] - a[1]) == 1 || abs(a[0] - a[3]) == 1 ||
        abs(a[0] - a[4]) == 1 || abs(a[0] - a[5]) == 1)
        return false;
    if (abs(a[1] - a[2]) == 1 || abs(a[1] - a[4]) == 1 ||
        abs(a[1] - a[5]) == 1 || abs(a[1] - a[6]) == 1)
        return false;
    if (abs(a[2] - a[5]) == 1 || abs(a[2] - a[6]) == 1)
        return false;
    if (abs(a[3] - a[4]) == 1 || abs(a[3] - a[7]) == 1 || abs(a[3] - a[8]) == 1)
        return false;
    if (abs(a[4] - a[5]) == 1 || abs(a[4] - a[7]) == 1 ||
        abs(a[4] - a[8]) == 1 || abs(a[4] - a[9]) == 1)
        return false;
    if (abs(a[5] - a[6]) == 1 || abs(a[5] - a[8]) == 1 || abs(a[5] - a[9]) == 1)
        return false;
    if (abs(a[6] - a[9]) == 1)
        return false;
    if (abs(a[7] - a[8]) == 1)
        return false;
    if (abs(a[8] - a[9]) == 1)
        return false;
    return true;
}

int main() {
    int count = 0;
    while (next_permutation(a, a + 10))
        if (check())
            count++;
    cout << count << endl;
    return 0;
}