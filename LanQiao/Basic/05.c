#include <stdio.h>
#include <string.h>

int idx[10010];

int main() {
    int i, t, n;
    scanf("%d", &n);
    memset(idx, -1, sizeof(idx));
    for (i = 1; i <= n; i++) {
        scanf("%d", &t);
        if (idx[t] == -1)
            idx[t] = i;
    }
    scanf("%d", &t);
    printf("%d", idx[t]);
    return 0;
}