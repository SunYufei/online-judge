/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k %= n;
        int count = 0;
        for (int start = 0; count < n; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
                ++count;
            } while (start != current);
        }
    }
};
// @lc code=end
