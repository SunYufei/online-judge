#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);
    int ans = 0;
    int cur = 0;
    int t;
    while (k--) {
        scanf("%d", &t);
        cur += t;
        if (cur > ans)
            ans = cur;
        if (cur < 0)
            cur = 0;
    }
    printf("%d", ans);
    return 0;
}