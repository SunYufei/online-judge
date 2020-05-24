/*
 * @lc app=leetcode.cn id=11 lang=javascript
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
    let res = 0, l = 0, r = height.length - 1;
    while (l < r) {
        const area = (r - l) * Math.min(height[l], height[r]);
        res = Math.max(res, area);
        if (height[l] <= height[r])
            ++l;
        else
            --r;
    }
    return res;
};
// @lc code=end

