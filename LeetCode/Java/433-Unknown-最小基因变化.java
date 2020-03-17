
/*
 * @lc app=leetcode.cn id=433 lang=java
 *
 * [433] 最小基因变化
 */
import java.util.*;

// @lc code=start
class Solution {
    int res = Integer.MAX_VALUE;
    String end;
    String[] bank;

    public int minMutation(String start, String end, String[] bank) {
        this.end = end;
        this.bank = bank;
        dfs(new HashSet<String>(), 0, start);
        return res == Integer.MAX_VALUE ? -1 : res;
    }

    void dfs(Set<String> set, int step, String current) {
        if (current.equals(end))
            res = Math.min(res, step);
        for (String s : bank) {
            int diff = 0;
            for (int i = 0; i < s.length(); i++)
                if (current.charAt(i) != s.charAt(i))
                    if (++diff > 1)
                        break;
            if (diff == 1 && !set.contains(s)) {
                set.add(s);
                dfs(set, step + 1, s);
                set.remove(s);
            }
        }
    }
}
// @lc code=end
