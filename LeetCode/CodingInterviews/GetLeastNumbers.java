package LeetCode;

import java.util.*;

class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0)
            return new int[0];
        Arrays.sort(arr);
        return Arrays.copyOf(arr, k);
    }
}