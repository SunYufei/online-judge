package Array;

import java.util.*;

class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> res = new ArrayList<>();
        int i = 1;
        while (target > 0) {
            target -= i++;
            if (target > 0 && target % i == 0) {
                int[] array = new int[i];
                for (int k = target / i, j = 0; k < target / i + i; k++, j++)
                    array[j] = k;
                res.add(array);
            }
        }
        Collections.reverse(res);
        return res.toArray(new int[0][]);
    }
}