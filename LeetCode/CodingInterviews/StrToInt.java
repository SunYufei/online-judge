package LeetCode;

class Solution {
    public int strToInt(String str) {
        if (str.length() == 0)
            return 0;
        char[] sc = str.toCharArray();
        int total = 0;
        int sign = 1;
        int index = 0;
        // trim
        while (index < sc.length && sc[index] == ' ')
            ++index;
        if (index == str.length())
            return 0;
        // sign
        if (sc[index] == '+' || sc[index] == '-')
            sign = sc[index++] == '+' ? 1 : -1;
        // value
        while (index < str.length()) {
            int digit = sc[index] - '0';
            if (digit < 0 || digit > 9)
                break;
            if (total > Integer.MAX_VALUE / 10 || total == Integer.MAX_VALUE / 10 && digit > Integer.MAX_VALUE % 10)
                return Integer.MAX_VALUE;
            if (total < Integer.MIN_VALUE / 10 || total == Integer.MIN_VALUE / 10 && digit > -(Integer.MIN_VALUE % 10))
                return Integer.MIN_VALUE;
            total = total * 10 + sign * digit;
            ++index;
        }
        return total;
    }
}