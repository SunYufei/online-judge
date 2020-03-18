
/*
 * @lc app=leetcode.cn id=84 lang=java
 *
 * [84] 柱状图中最大的矩形
 */
import java.util.*;

// @lc code=start
class Solution {
    public int largestRectangleArea(int[] heights) {
        int res = 0;
        var stack = new Stack<Integer>();
        stack.push(-1);
        for (int i = 0; i < heights.length; i++) {
            while (stack.peek() != -1 && heights[stack.peek()] >= heights[i])
                res = Math.max(res, heights[stack.pop()] * (i - stack.peek() - 1));
            stack.push(i);
        }
        while (stack.peek() != -1)
            res = Math.max(res, heights[stack.pop()] * (heights.length - stack.peek() - 1));
        return res;
    }
}
// @lc code=end
