import java.util.Scanner;

public class Chinese2Unicode {
public static void main(String args[]){
    Scanner scanner = new Scanner(System.in);
    String string;
    while (true) {
        string = scanner.next();
        if (string.isEmpty())
            break;
        System.out.println(str2Unicode(string));
    }
    scanner.close();
}
public static String str2Unicode(String str){
    StringBuffer unicode = new StringBuffer();
    int length = str.length();
    char c;
    int t;
    for (int i = 0; i < length; i++) {
        c = str.charAt(i);
        if (c >= 128)
            unicode.append("\\u" + Integer.toHexString(c));
        else
            unicode.append(c);
    }
    return unicode.toString();
}
}