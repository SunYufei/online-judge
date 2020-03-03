public class Merge {
    public static void main(String[] args) {
        int[] A = { 1, 2, 3, 0, 0, 0 };
        int[] B = { 2, 5, 6 };
        merge(A, 3, B, 3);
        for (var i : A) {
            System.out.print(i);
            System.out.print('\t');
        }
    }

    private static void merge(int[] A, int m, int[] B, int n) {
        int pa = m - 1;
        int pb = n - 1;
        int i = m + n - 1;
        // merge
        while (pa >= 0 && pb >= 0)
            A[i--] = A[pa] > B[pb] ? A[pa--] : B[pb--];
        // merge rest
        while (pa >= 0)
            A[i--] = A[pa--];
        while (pb >= 0)
            A[i--] = B[pb--];
    }
}