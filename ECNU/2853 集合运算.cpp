#include <bits/stdc++.h>
using namespace std;

void print(set<int> &s) {
    printf("{");
    if (!s.empty()) {
        printf("%d", *(s.begin()));
        for (auto it = ++s.begin(); it != s.end(); ++it)
            printf(",%d", *it);
    }
    printf("}\n");
}

int main() {
    int m, n, t;
    set<int> x, y, a, b, c;
    scanf("%d%d", &m, &n);
    while (m--) {
        scanf("%d", &t);
        x.insert(t);
    }
    while (n--) {
        scanf("%d", &t);
        y.insert(t);
    }
    set_intersection(x.begin(), x.end(), y.begin(), y.end(),
                     inserter(a, a.end()));
    set_union(x.begin(), x.end(), y.begin(), y.end(), inserter(b, b.end()));
    set_difference(x.begin(), x.end(), y.begin(), y.end(),
                   inserter(c, c.end()));
    print(a);
    print(b);
    print(c);
    return 0;
}