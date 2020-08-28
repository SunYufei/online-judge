public class MethodDemo {
    public static void main(String[] args){
        method();
    }
    // 这里要加上 static 关键字 因为静态方法只能调用静态方法
    public static void method(){
        System.out.println("方法被调用");
    }
}