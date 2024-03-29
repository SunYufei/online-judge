package LeetCode.CodingInterviews.Java;

import java.util.Collections;
import java.util.Arrays;

class Solution {
    public String reverseWords(String s) {
        String[] words = s.trim().split(" +");
        Collections.reverse(Arrays.asList(words));
        return String.join(" ", words);
    }
}