/*
 * @lc app=leetcode.cn id=49 lang=java
 *
 * [49] 字母异位词分组
 */

import java.util.*;

// @lc code=start
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0)
            return new ArrayList();
        var res = new HashMap<String, List>();

        for (String s : strs) {
            var ca = s.toCharArray();
            Arrays.sort(ca);
            var key = String.valueOf(ca);
            if (!res.containsKey(key))
                res.put(key, new ArrayList());
            res.get(key).add(s);
        }

        return new ArrayList(res.values());
    }
}
// @lc code=end
