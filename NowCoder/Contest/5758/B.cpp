#include <bits/stdc++.h>
using namespace std;

int a[100010];

int helper(int left, int right) {
    if (left > right)
        return 0;
    while (left < right && a[left] == 1)
        ++left;
    while (left < right && a[right] == 1)
        ++right;
    int res = (*min_element(a + left, a + right + 1)) - 1;
    for (int i = left; i <= right; ++i)
        a[i] -= res;
    for (int i = left; i <= right; ++i)
        if (a[i] == 1) {
            res += helper(left, i - 1);
            left = i + 1;
        }
    res += helper(left, right);
    return res;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int l = 0, r = n - 1;
        while (l <= r && a[l] == 1)
            ++l;
        while (l <= r && a[r] == 1)
            --r;
        int res = helper(l, r);
        printf("%d\n", res);
    }
    return 0;
}