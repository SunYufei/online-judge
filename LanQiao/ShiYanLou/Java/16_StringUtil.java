import java.util.Scanner;

public class StringUtil {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) != ' ') {
                System.out.print(str.charAt(i));
            }
        }
        System.out.println();
    }
}