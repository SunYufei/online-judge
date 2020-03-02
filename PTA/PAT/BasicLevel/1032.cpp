#include <iostream>
using namespace std;
int main() {
    int n, i, school, score, max = -1, maxn;
    cin >> n;
    int *c = new int[n + 1];
    for (i = 1; i < n + 1; i++)
        c[i] = 0;
    for (i = 1; i < n + 1; i++) {
        cin >> school >> score;
        c[school] += score;
    }
    for (i = n; i > 0; i--) {
        if (c[i] > max) {
            max = c[i];
            maxn = i;
        }
    }
    cout << maxn << " " << c[maxn];
    delete[] c;
    return 0;
}
