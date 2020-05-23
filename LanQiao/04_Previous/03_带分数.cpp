#include <bits/stdc++.h>
using namespace std;

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int getnum(int start, int end) {
    int n = 0;
    for (int i = start; i < end; i++) {
        n *= 10;
        n += arr[i];
    }
    return n;
}

int main() {
    int a, b, c, n, count = 0, i, j, k;
    cin >> n;
    while (next_permutation(arr, arr + 9)) {
        for (i = 1; i <= 7; i++) {
            a = getnum(0, i);
            for (j = i + 1; j <= 8; j++) {
                b = getnum(i, j);
                c = getnum(j, 9);
                if (n - a == double(b) / c)
                    count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}