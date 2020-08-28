import java.util.Scanner;

public class ContrastString {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String a = in.nextLine();
        String b = in.nextLine();
        if (check(a, b)) {
            System.out.println("相同");
        } else {
            System.out.println("不同");
        }
    }

    private static boolean check(String a, String b) {
        if (a.length() != b.length()) {
            return false;
        }
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                return false;
            }
        }
        return true;
    }
}