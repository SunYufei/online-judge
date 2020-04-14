#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    sort(nums.begin(), nums.end());
    printf("%d", *nums.begin());
    for (auto it = nums.begin() + 1; it < nums.end(); ++it)
        printf(" %d", *it);
    return 0;
}