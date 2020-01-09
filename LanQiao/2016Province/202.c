/*
    小明想在控制台上输出m*n个方格

    代码填空

    for (col = 0; col < m; col++)
        printf("---+");
*/
#include <stdio.h>

// 打印 m 列，n 行的方格
void f(int m, int n) {
    int row;
    int col;

    for (row = 0; row < n; row++) {
        for (col = 0; col < m; col++)
            printf("+---");
        printf("+\n");
        for (col = 0; col < m; col++)
            printf("|   ");
        printf("|\n");
    }
    printf("+");
    ////////////////////////////////////////
    for (col = 0; col < m; col++)
        printf("---+");
    ///////////////////////////////////////
    printf("\n");
}

int main() {
    f(10, 4);
    return 0;
}