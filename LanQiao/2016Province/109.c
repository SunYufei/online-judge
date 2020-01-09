/*
    生日蜡烛

    某君从某年开始每年都举办一次生日party，
    并且每次都要吹熄与年龄相同根数的蜡烛。

    现在算起来，他一共吹熄了236根蜡烛。

    请问，他从多少岁开始过生日party的？

    请填写他开始过生日party的年龄数。
    注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

    26
*/
#include <stdio.h>

int main() {
    int start, len;
    for (start = 1; start <= 100; start++)
        for (len = 1; len <= 100; len++)
            if ((start + start + len) * (len + 1) == 236 * 2)
                printf("%d %d\n", start, len);
    return 0;
}