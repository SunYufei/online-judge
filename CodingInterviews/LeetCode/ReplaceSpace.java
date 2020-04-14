package LeetCode;

class Solution {
    public String replaceSpace(String s) {
        var builder = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == ' ')
                builder.append("%20");
            else
                builder.append(c);
        }
        return builder.toString();
    }
}