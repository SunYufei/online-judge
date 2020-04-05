/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include "main.h"

// @lc code=start
class Solution {
    int partition(vector<int> &nums, int l, int r) {
        int pivot = r, counter = l;
        for (int i = l; i < r; i++)
            if (nums[i] < nums[pivot])
                swap(nums[counter++], nums[i]);
        swap(nums[pivot], nums[counter]);
        return counter;
    }

    void quick_sort(vector<int> &nums, int l, int r) {
        if (l < r) {
            int p = partition(nums, l, r);
            quick_sort(nums, l, p - 1);
            quick_sort(nums, p + 1, r);
        }
    }

  public:
    vector<int> sortArray(vector<int> &nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end
