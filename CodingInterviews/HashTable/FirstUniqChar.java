package HashTable;

class Solution {
    public char firstUniqChar(String s) {
        int[] hash = new int[26];
        for (char c : s.toCharArray())
            ++hash[c - 'a'];
        for (char c : s.toCharArray())
            if (hash[c - 'a'] == 1)
                return c;
        return ' ';
    }
}