/*
 * @lc app=leetcode.cn id=1 lang=javascript
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    let map = {}, i = 0, diff;
    while (i < nums.length) {
        diff = target - nums[i];
        if (map[diff] != undefined)
            return [map[diff], i];
        map[nums[i]] = i;
        i += 1;
    }
    return [];
};
// @lc code=end

