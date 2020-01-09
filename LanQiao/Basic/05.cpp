#include <stdio.h>
#include <string.h>

int main() {
    int i, a, n, ans;
    int v[1010];
    memset(v, 0, sizeof(v));
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    scanf("%d", &a);
    ans = -1;
    for (i = 1; i <= n; i++)
        if (v[i] == a) {
            ans = i;
            break;
        }
    printf("%d", ans);
    return 0;
}