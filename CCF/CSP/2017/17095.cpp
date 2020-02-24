#include <stdio.h>
#define MAXN 100005
typedef long long LL;
LL tree[MAXN];
int num[MAXN];
int N, M;

void update(int i, int val) {
    while (i <= N) {
        tree[i] += val;
        i += i & -i;
    }
}

LL sum(int i) {
    LL ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= i & -i;
    }
    return ret;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &num[i]);
        update(i, num[i]);
    }
    int opt, l, r, v;
    for (int i = 0; i < M; i++) {
        scanf("%d", &opt);
        if (opt == 2) {
            scanf("%d%d", &l, &r);
            printf("%lld\n", sum(r) - sum(l - 1));
        } else {
            scanf("%d%d%d", &l, &r, &v);
            if (v == 1)
                continue;
            for (int j = l; j <= r; j++) {
                if (num[j] >= v && num[j] % v == 0) {
                    update(j, num[j] / v - num[j]);
                    num[j] /= v;
                }
            }
        }
    }
    return 0;
}