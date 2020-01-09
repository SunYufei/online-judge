#include <bits/stdc++.h>
using namespace std;

// m个A, n个B
int f(int m, int n) {
    if (m == 0 || n == 0)
        return 1;
    return f(m - 1, n) + f(m, n - 1);
}

void permutation(char a[], int size, int k) {
    if (k == size) {
        // Found one permutation
        return;
    }
    for (int i = k; i < size; i++) {
        swap(a[k], a[i]);
        permutation(a, size, k + 1);
        swap(a[k], a[i]);
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort(a, a + 9);
    while (next_permutation(a, a + 9)) {
        // do something
    }
    return 0;
}