/*
 * @lc app=leetcode.cn id=15 lang=java
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;

        Arrays.sort(nums);

        for (int t = 0; t < n - 2; t++) {
            if (nums[t] > 0)
                return res;
            if (t > 0 && nums[t] == nums[t - 1])
                continue;

            int l = t + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[t] + nums[l] + nums[r];
                if (sum == 0) {
                    res.add(Arrays.asList(nums[t], nums[l], nums[r]));
                    while (l + 1 < r && nums[l] == nums[l + 1])
                        ++l;
                    while (l < r - 1 && nums[r] == nums[r - 1])
                        --r;
                    ++l;
                    --r;
                } else if (sum < 0)
                    ++l;
                else
                    --r;
            }
        }

        return res;
    }
}
// @lc code=end
