#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, t;
    int a[101] = {0};
    vector<int> v;
    vector<int>::iterator it;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &t);
        a[t]++;
    }
    scanf("%d", &K);
    while (K--) {
        scanf("%d", &t);
        v.push_back(t);
    }
    for (it = v.begin(); it < v.end() - 1; it++)
        printf("%d ", a[*it]);
    printf("%d", a[*it]);
    return 0;
}
