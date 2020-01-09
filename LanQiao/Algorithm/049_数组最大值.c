// 注意C99编译器不支持for(int i = 0; i < n; i++){}
#include <stdio.h>

int main() {
    int n, t, i;
    scanf("%d", &n);
    int max = -999999999;
    int idx = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t > max) {
            max = t;
            idx = i;
        }
    }
    printf("%d %d", max, idx);
    return 0;
}