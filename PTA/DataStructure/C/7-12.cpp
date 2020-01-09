#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, n, a[100010];
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (i = 0; i < n - 1; ++i)
        printf("%d ", a[i]);
    printf("%d", a[i]);
    return 0;
}