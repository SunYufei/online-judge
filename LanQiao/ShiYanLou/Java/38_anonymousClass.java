// Outer.java
public class Outer {

    public Inner getInner(final String name, String city) {
        return new Inner() {
            private String nameStr = name;
            public String getName() {
                return nameStr;
            }
        };
    }

    public static void main(String[] args) {
        Outer outer = new Outer();
        Inner inner = outer.getInner("Inner", "NewYork");
        System.out.println(inner.getName());
    }
}

interface Inner {
    String getName();
}

public Inner getInner(final String name, String city) {
  return new Inner(name, city) {
    private String nameStr = name;

    public String getName() {
      return nameStr;
    }
  };
}