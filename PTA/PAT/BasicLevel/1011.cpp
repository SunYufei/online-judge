#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, i;
    scanf("%d", &t);
    long a, b, c;
    for (i = 1; i <= t; i++) {
        scanf("%ld%ld%ld", &a, &b, &c);
        printf("Case #%d: ", i);
        if (a + b > c)
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}
