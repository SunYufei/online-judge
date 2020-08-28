// Animal.java
public class Animal {
    public Animal(){
        System.out.println("我是动物");
    }
}

// Dog.java
public class Dog extends Animal {
    public Dog(){
        System.out.println("我是狗");
    }
}

// Test.java
public class Test {

  /*
  注意：定义带类型参数的方法，其主要目的是为了表达多个参数以及返回值之间的关系。例如本例子中T和S的继承关系， 返回值的类型和第一个类型参数的值相同。
  */
    public<T, S extends T> T testDemo(T t, S s){
        System.out.println("我是 T 类型，我的类型是" + t.getClass().getName());
        System.out.println("我是 S 类型，我的类型是" + s.getClass().getName());
        return t;
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Test test = new Test();
        Dog d = new Dog();
        Animal a0 = new Animal();
        Animal a1  = test.testDemo(a0, d);
        System.out.println("我是对象 a1，我的类型是" + a1.getClass().getName());
    }
}

import java.util.List;
import java.util.ArrayList;

public class Test {

  // List<?> 表示接受一个元素为任意类型的列表 List。
    public void testDemo(List<?> s){
        for(Object obj:s){
            System.out.println("我的类型是" + obj.getClass().getName());
        }
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Test test = new Test();
        Dog a0 = new Dog();
        Animal a1 = new Animal();
    // 声明一个接收元素类型是 Animal 的列表 List s。
    // 然后创建一个元素类型是 Animal 的 ArrayList 赋值给 s。
        List<Animal> s = new ArrayList<Animal>();
    // Dog a0 是 Animal 的子类，可以向上转型为 Animal 类型
        s.add(a0);
        s.add(a1);
        test.testDemo(s);
    }

}