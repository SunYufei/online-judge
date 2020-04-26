#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100010

int a[MAXN], b[MAXN];

void build(int n, int t[]) {
    memset(t, -1, sizeof(int) * MAXN);
    int data, idx;
    while (n--) {
        idx = 1;
        scanf("%d", &data);
        while (1) {
            if (t[idx] == -1) {
                t[idx] = data;
                break;
            } else if (data < t[idx])
                idx <<= 1;
            else
                idx = idx * 2 + 1;
        }
    }
}

int check(int n) {
    for (int i = 1; i <= 2 * n + 1; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

int main() {
    int n, l;
    while (scanf("%d", &n) != EOF && n != 0) {
        scanf("%d", &l);
        build(n, a);
        while (l--) {
            build(n, b);
            if (check(n))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}