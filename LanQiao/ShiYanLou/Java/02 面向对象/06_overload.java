public class Test {
    void f(int i) {
        System.out.println("i=" + i);
    }

    void f(float f) {
        System.out.println("f=" + f);
    }

    void f(String s) {
        System.out.println("s=" + s);
    }

    void f(String s1, String s2){
        System.out.println("s1+s2="+(s1+s2));
    }

    void f(String s, int i){
        System.out.println("s="+s+",i="+i);
    }

    public static void main(String[] args) {
        Test test = new Test();
        test.f(3456);
        test.f(34.56f);
        test.f("abc");
        test.f("abc","def");
        test.f("abc",3456);
    }
}

public class Animal {
    //类方法
    public void bark() {
        System.out.println("动物叫！");
    }
}

public class Dog extends Animal {
       //重写父类的bark方法
        public void bark() {
        System.out.println("汪！汪！汪！");
    }
}

public class Test{
    public static void main(String args[]){
           Animal a = new Animal(); // Animal 对象
        Dog d = new Dog();   // Dog 对象

          Animal b = new Dog(); // Dog 对象,向上转型为Animal类型，具体会在后面的内容进行详解

          a.bark();// 执行 Animal 类的方法
         d.bark();//执行 Dog 类的方法
          b.bark();//执行 Dog 类的方法
       }
}