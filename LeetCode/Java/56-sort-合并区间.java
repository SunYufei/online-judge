import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=56 lang=java
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length <= 1)
            return intervals;
        Arrays.sort(intervals, (a1, a2) -> Integer.compare(a1[0], a2[0]));
        int[] current = intervals[0];
        var res = new ArrayList<int[]>();
        res.add(current);

        for (var interval : intervals) {
            int currBegin = current[0];
            int currEnd = current[1];
            int nextBegin = interval[0];
            int nextEnd = interval[1];
            if (currEnd >= nextBegin)
                current[1] = Math.max(currEnd, nextEnd);
            else {
                current = interval;
                res.add(current);
            }
        }

        return res.toArray(new int[res.size()][]);
    }
}
// @lc code=end
