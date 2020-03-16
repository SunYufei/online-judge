class Solution {
    public String compressString(String S) {
        if (S.length() == 0)
            return S;

        var builder = new StringBuilder();

        var sc = S.toCharArray();
        char ch = sc[0];
        int count = 1;

        for (int i = 1; i < sc.length; i++) {
            if (ch == sc[i])
                count++;
            else {
                builder.append(ch);
                builder.append(count);
                ch = sc[i];
                count = 1;
            }
        }

        builder.append(ch);
        builder.append(count);

        var res = builder.toString();
        return res.length() >= S.length() ? S : res;
    }
}

public class CompressString {
    public static void main(String[] args) {
        var sol = new Solution();
        System.out.println(sol.compressString("aabcccccaaa"));
        System.out.println(sol.compressString("abbccd"));
    }
}