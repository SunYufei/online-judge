class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0)
            return new int[0];
        int rows = matrix.length;
        int cols = matrix[0].length;
        var res = new int[rows * cols];

        int l = 0;
        int r = cols - 1;
        int t = 0;
        int b = rows - 1;
        int p = 0;

        while (true) {
            for (int i = l; i <= r; i++)
                res[p++] = matrix[t][i];
            if (++t > b)
                break;
            for (int i = t; i <= b; i++)
                res[p++] = matrix[i][r];
            if (l > --r)
                break;
            for (int i = r; i >= l; --i)
                res[p++] = matrix[b][i];
            if (t > --b)
                break;
            for (int i = b; i >= t; --i)
                res[p++] = matrix[i][l];
            if (++l > r)
                break;
        }

        return res;
    }
}

public class SpiralOrder {
    public static void main(String[] args) {
        var sol = new Solution();
        var matrix = new int[][] { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        var res = sol.spiralOrder(matrix);
        System.out.println(res);
    }
}