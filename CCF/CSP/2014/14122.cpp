#include <stdio.h>
#define MAXN 505
int mat[MAXN][MAXN];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int i = 0, j = 0;
    int dir = 0;  //-1控制右上走，1控制左下走
    while (i >= 0 && i < n && j >= 0 && j < n) {
        printf("%d ", mat[i][j]);  //到达边界时
        if (i == n - 1 && j == n - 1)
            break;                   //超出边界，退出
        if (i == 0 && j != n - 1) {  //第一行，不是最后一列，向右走一步
            j++;
            dir = 1;
            printf("%d ", mat[i][j]);
        } else if (j == 0 && i != n - 1) {  //第一列，不是最后一行，向下走一步
            i++;
            dir = -1;
            printf("%d ", mat[i][j]);
        } else if (i == n - 1) {  //最后一行，不是第一列，向右走一步
            j++;
            dir = -1;
            printf("%d ", mat[i][j]);
        } else if (j == n - 1) {  //最后一列，不是第一行，向下走一步
            i++;
            dir = 1;
            printf("%d ", mat[i][j]);
        }
        i += dir;  //斜着走，直到到达边界
        j -= dir;
    }
    return 0;
}