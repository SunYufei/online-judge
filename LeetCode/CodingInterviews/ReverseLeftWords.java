package LeetCode;

class Solution {
    public String reverseLeftWords(String s, int n) {
        int len = s.length();
        if (len == 0)
            return "";
        n = n % len;
        var builder = new StringBuilder();
        for (int i = n; i < len; i++)
            builder.append(s.charAt(i));
        for (int i = 0; i < n; i++)
            builder.append(s.charAt(i));
        return builder.toString();
    }
}