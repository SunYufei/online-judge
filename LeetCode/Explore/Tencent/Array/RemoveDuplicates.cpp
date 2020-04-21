#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        int p = 0;
        for (int i = 0; i < size; i++)
            if (nums[i] != nums[p])
                nums[++p] = nums[i];
        return p + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = sol.removeDuplicates(nums);
    for (int i = 0; i < n; i++)
        cout << nums[i] << "\t";
    return 0;
}