/*

    凑算式

         B     DEF
    A + --- + ----- = 10
         C     GHI

    （如果显示有问题，可以参见【图1.jpg】）

    这个算式中A~I代表1~9的数字，不同的字母代表不同的数字。

    比如：
    6+8/3+952/714 就是一种解法，
    5+3/1+972/486 是另一种解法。

    这个算式一共有多少种解法？

    注意：你提交应该是个整数，不要填写任何多余的内容或说明性文字。

    29
*/
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = 0;
    double left, right;
    while (next_permutation(a, a + 9)) {
        right = 10 - a[0];
        left = double(a[1]) / a[2];
        left += double(a[3] * 100 + a[4] * 10 + a[5]) /
                (a[6] * 100 + a[7] * 10 + a[8]);
        if (abs(left - right) < 1e-6)
            count++;
    }
    cout << count << endl;
    return 0;
}