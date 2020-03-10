class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        int m = matrix.length;
        if (m == 0)
            return false;
        int n = matrix[0].length;

        int i = n - 1, j = 0;
        while (i >= 0 && j < m) {
            if (matrix[j][i] == target)
                return true;
            else if (matrix[j][i] < target)
                ++j;
            else
                --i;
        }

        return false;
    }
}

public class FindNumberIn2DArray {
    public static void main(String[] args) {
        var sol = new Solution();
        int[][] matrix = { { 1, 4, 7, 11, 15 }, { 2, 5, 8, 12, 19 }, { 3, 6, 9, 16, 22 }, { 10, 13, 14, 17, 24 },
                { 18, 21, 23, 26, 30 } };
        System.out.print(sol.findNumberIn2DArray(matrix, 5));
        System.out.print(sol.findNumberIn2DArray(matrix, 20));
    }
}