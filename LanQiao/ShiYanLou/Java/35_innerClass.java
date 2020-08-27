// People.java
//外部类People
public class People {
    private String name = "LiLei";         //外部类的私有属性
    //内部类Student
    public class Student {
        String ID = "20151234";               //内部类的成员属性
        //内部类的方法
        public void stuInfo(){
            System.out.println("访问外部类中的name：" + name);
            System.out.println("访问内部类中的ID：" + ID);
        }
    }

    //测试成员内部类
    public static void main(String[] args) {
        People a = new People();     //创建外部类对象，对象名为a
        Student b = a.new Student(); //使用外部类对象创建内部类对象，对象名为b
        // 或者为 People.Student b = a.new Student();
        b.stuInfo();   //调用内部对象的suInfo方法
    }
}