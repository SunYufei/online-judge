#include <bits/stdc++.h>
using namespace std;

void vector_unique(vector<int> v) {
    sort(v.begin(), v.end(), greater<int>());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int main() {
    vector<int> v;
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0);
    reverse(v.begin(), v.end());
    return 0;
}