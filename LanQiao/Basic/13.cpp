#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    printf("%d", *(v.begin()));
    for (vector<int>::iterator it = v.begin() + 1; it < v.end(); ++it)
        printf(" %d", *it);
    return 0;
}