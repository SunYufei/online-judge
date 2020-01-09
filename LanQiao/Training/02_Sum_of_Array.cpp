#include <bits/stdc++.h>
using namespace std;

int f(int a[], int size) {
    int sum = a[size - 1];
    if (size > 0)
        sum += f(a, size - 1);
    return sum;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int sum1 = f(a, sizeof(a) / sizeof(a[0]));
    int sum2 = accumulate(a, a + sizeof(a) / sizeof(a[0]), 0);
    cout << sum1 << " " << sum2 << endl;
    return 0;
}