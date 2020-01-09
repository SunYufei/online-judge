#include <iostream>
using namespace std;

// 产生一定量的随机数
void GetRands(int a[], int maxRange = 5, const int count = 5) {
    // srand()
    int i, j, t;
    for (i = 0; i < count; ++i) {
        t = rand() % maxRange;
        for (j = 0; j < i; ++j) {
            if (a[j] == t) {
                break;
            }
        }
        if (j < i) {
            --i;
            continue;
        }
        a[i] = t;
    }
}
