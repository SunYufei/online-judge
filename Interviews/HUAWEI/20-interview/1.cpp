#include <bits/stdc++.h>
using namespace std;

vector<int> threeSum(vector<int> &arr, int d) {
    if (arr.size() < 3)
        return {};
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 2; i++) {
        if (arr[i] > d) {
            break;
        }
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int l = i + 1, r = arr.size() - 1;
        while (l < r) {
            int sum = arr[i] + arr[l] + arr[r];
            if (sum == d) {
                return {arr[i], arr[l], arr[r]};
            } else if (sum < d) {
                l++;
            } else if (sum > d) {
                r--;
            }
        }
    }
    return {};
}

int main() {
    vector<int> arr = {1, 2, 2, 3};
    int d = 5;
    vector<int> res = threeSum(arr, d);
    for (auto v : res) {
        cout << v << endl;
    }
    return 0;
}