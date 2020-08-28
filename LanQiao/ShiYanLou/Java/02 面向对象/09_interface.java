// Animal.java
interface Animal {
    //int x;
    //编译错误,x需要初始化，因为是 static final 类型
    int y = 5;
    public void eat();
    public void travel();
}

// Cat.java
public class Cat implements Animal{

     public void eat(){
         System.out.println("Cat eats");
     }

     public void travel(){
         System.out.println("Cat travels");
     }
     public static void main(String[] args) {
        Cat cat = new Cat();
        cat.eat();
        cat.travel();
    }
}