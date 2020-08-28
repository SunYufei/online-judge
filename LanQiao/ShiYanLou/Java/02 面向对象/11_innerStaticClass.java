// People.java
//外部类People
public class People {
    private String name = "LiLei";         //外部类的私有属性

/*外部类的静态变量。
Java 中被 static 修饰的成员称为静态成员或类成员。它属于整个类所有，而不是某个对象所有，即被类的所有对象所共享。静态成员可以使用类名直接访问，也可以使用对象名进行访问。
*/
    static String ID = "510xxx199X0724XXXX";

    //静态内部类Student
    public static class Student {
        String ID = "20151234";               //内部类的成员属性
        //内部类的方法
        public void stuInfo(){
            System.out.println("访问外部类中的name：" + (new People().name));
            System.out.println("访问外部类中的ID：" + People.ID);
            System.out.println("访问内部类中的ID：" + ID);
        }
    }

    //测试成员内部类
    public static void main(String[] args) {
        Student b = new Student();   //直接创建内部类对象，对象名为b
        b.stuInfo();                 //调用内部对象的suInfo方法
    }
}