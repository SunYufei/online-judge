#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> count;
    int n, t;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        ++count[t];
    }
    for (auto it = count.begin(); it != count.end(); ++it)
        printf("%d:%d\n", it->first, it->second);
    return 0;
}