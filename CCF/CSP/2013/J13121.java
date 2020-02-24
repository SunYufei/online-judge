import java.util.Scanner;

class J13121 {

    private static int[] count = new int[10010];

    public static void main(String[] args) {
        for (int i = 0; i < 10010; ++i)
            count[i] = 0;

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        for (int i = 1; i <= n; ++i) {
            int s = scanner.nextInt();
            ++count[s];
        }

        int mnum = 0;
        int mid = 0;
        for (int i = 1; i <= 10000; ++i) {
            if (count[i] > mnum) {
                mid = i;
                mnum = count[i];
            }
        }

        System.out.print(mid);

        scanner.close();
    }
}