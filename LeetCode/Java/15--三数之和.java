
/*
 * @lc app=leetcode.cn id=15 lang=java
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.71%)
 * Likes:    1865
 * Dislikes: 0
 * Total Accepted:    167.5K
 * Total Submissions: 649.8K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();

        int n = nums.length;

        // sort
        Arrays.sort(nums);

        for (int i = 0; i < n - 2; i++) {
            // 当前数 > 0，不会有三数相加为 0 的情况
            if (nums[i] > 0)
                return ans;
            // 去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int L = i + 1;
            int R = n - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    ans.add(Arrays.asList(nums[i], nums[L], nums[R]));
                    // 去重
                    while (L + 1 < R && nums[L] == nums[L + 1])
                        ++L;
                    while (L < R - 1 && nums[R] == nums[R - 1])
                        --R;
                    // 指针移动
                    ++L;
                    --R;
                } else if (sum < 0)
                    ++L;
                else if (sum > 0)
                    --R;
            }
        }
        return ans;
    }
}
// @lc code=end
