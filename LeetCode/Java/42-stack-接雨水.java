
/*
 * @lc app=leetcode.cn id=42 lang=java
 *
 * [42] 接雨水
 */
import java.util.*;

// @lc code=start
class Solution {
    public int trap(int[] height) {
        int res = 0;
        int current = 0;
        var stack = new Stack<Integer>();
        while (current < height.length) {
            while (!stack.empty() && height[current] > height[stack.peek()]) {
                int top = stack.pop();
                if (stack.empty())
                    break;
                int distance = current - stack.peek() - 1;
                int boundedHeight = Math.min(height[current], height[stack.peek()]) - height[top];
                res += distance * boundedHeight;
            }
            stack.push(current++);
        }
        return res;
    }
}
// @lc code=end
