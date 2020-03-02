#include <bits/stdc++.h>
using namespace std;

int main() {
    float w, h;
    float ans;
    cin >> w >> h;
    ans = w / h / h;
    printf("%.1f\n", ans);
    if (ans - 25 > 1e-8)
        printf("PANG\n");
    else
        printf("Hai Xing\n");
    return 0;
}