
/*
 * @lc app=leetcode.cn id=820 lang=java
 *
 * [820] 单词的压缩编码
 */
import java.util.*;

// @lc code=start
class Solution {
    class TrieNode {
        TrieNode[] children;
        int count;

        public TrieNode() {
            children = new TrieNode[26];
            count = 0;
        }

        public TrieNode get(char c) {
            if (children[c - 'a'] == null) {
                children[c - 'a'] = new TrieNode();
                ++count;
            }
            return children[c - 'a'];
        }
    }

    public int minimumLengthEncoding(String[] words) {
        TrieNode trie = new TrieNode();
        Map<TrieNode, Integer> nodes = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            TrieNode cur = trie;
            for (int j = word.length() - 1; j >= 0; --j)
                cur = cur.get(word.charAt(j));
            nodes.put(cur, i);
        }
        int res = 0;
        for (TrieNode node : nodes.keySet())
            if (node.count == 0)
                res += words[nodes.get(node)].length() + 1;
        return res;
    }
}
// @lc code=end
