#include <stdio.h>
int board[15][10];
int block[4][4];
int main() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &block[i][j]);
        }
    }

    int lp;
    scanf("%d", &lp);
    int i, j, k;
    for (i = 1; i <= 15; i++) {
        // i:方块向下移动i次。（实际上，方块最多向下移动i-1次）
        for (j = 3; j >= 0; j--) {     // i+j:方块当前位置的下一行
            for (k = 0; k < 4; k++) {  // k:方块的列
                if (block[j][k] == 1 &&
                    (board[i + j][lp + k - 1] == 1 ||
                     i + j == 15)) {  //如果下一行有1，或者到达底部
                    goto end;
                }
            }
        }
    }

end:
    for (int j = 3; j >= 0; j--) {
        for (int k = 0; k < 4; k++) {
            if (block[j][k] == 1)
                board[j + i - 1][lp + k - 1] = 1;
        }
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}