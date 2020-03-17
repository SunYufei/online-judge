/*
 * @lc app=leetcode.cn id=45 lang=java
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
    public int jump(int[] nums) {
        int res = 0;
        int start = 0;
        int end = 1;
        while (end < nums.length) {
            int maxPos = 0;
            for (int i = start; i < end; i++)
                maxPos = Math.max(maxPos, i + nums[i]);
            start = end;
            end = maxPos + 1;
            ++res;
        }
        return res;
    }
}
// @lc code=end
