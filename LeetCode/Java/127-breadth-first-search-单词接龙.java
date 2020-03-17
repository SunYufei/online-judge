
/*
 * @lc app=leetcode.cn id=127 lang=java
 *
 * [127] 单词接龙
 */
import java.util.*;

// @lc code=start
class Solution {

    private class Pair {
        String word;
        int level;

        Pair(String word, int level) {
            this.word = word;
            this.level = level;
        }
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int n = beginWord.length();

        var allComboDict = new HashMap<String, ArrayList<String>>();

        for (String word : wordList)
            for (int i = 0; i < n; i++) {
                String newWord = word.substring(0, i) + '*' + word.substring(i + 1, n);
                var trans = allComboDict.getOrDefault(newWord, new ArrayList<String>());
                trans.add(word);
                allComboDict.put(newWord, trans);
            }

        Queue<Pair> q = new LinkedList();
        q.add(new Pair(beginWord, 1));

        var visited = new HashMap<String, Boolean>();
        visited.put(beginWord, true);

        while (!q.isEmpty()) {
            Pair node = q.remove();
            String word = node.word;
            int level = node.level;

            for (int i = 0; i < n; i++) {
                String newWord = word.substring(0, i) + '*' + word.substring(i + 1, n);

                for (String s : allComboDict.getOrDefault(newWord, new ArrayList<String>())) {
                    if (s.equals(endWord))
                        return level + 1;
                    if (!visited.containsKey(s)) {
                        visited.put(s, true);
                        q.add(new Pair(s, level + 1));
                    }
                }
            }
        }

        return 0;
    }
}
// @lc code=end
