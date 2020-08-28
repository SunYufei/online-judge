import java.util.Scanner;

public class PrintWeek {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        System.out.print("今天是星期");
        System.out.println(" 一二三四五六日".charAt(x));
    }
}