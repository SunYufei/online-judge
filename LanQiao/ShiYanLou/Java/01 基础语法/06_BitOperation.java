public class BitOperation {
    public static void main(String args[]) {
        int a = 60;
        int b = 13;
        System.out.println("a & b = " + (a & b));
        System.out.println("a | b = " + (a | b));
        System.out.println("a ^ b = " + (a ^ b));
        System.out.println("~a = " + (~a));
        System.out.println("a << 2 = " + (a << 2));
        System.out.println("a >> 2 = " + (a >> 2));
        System.out.println("a >>> 2 = " + (a >>> 2));
    }
}
/*
    a & b = 12
    a | b = 61
    a ^ b = 49
    ~a = -61
    a << 2 = 240
    a >> 2 = 15
    a >>> 2 = 15
*/