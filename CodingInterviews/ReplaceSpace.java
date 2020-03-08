class Solution {
    public String replaceSpace(String s) {
        StringBuilder ans = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == ' ')
                ans.append("%20");
            else
                ans.append(c);
        }
        return ans.toString();
    }
}

public class ReplaceSpace {
    public static void main(String[] args) {
        String s = "We are happy.";
        var sol = new Solution();
        System.out.println(sol.replaceSpace(s));
    }
}
