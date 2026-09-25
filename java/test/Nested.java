public class Lmao {
  public class Inner {
    public void hello() {
      System.out.println("hello");
    }
  }

  public static class Hello {
    public void lmao(String nice) {
      System.out.println(nice);
    }
  }
}

public class Nested {
  public static void main(String[] args) {
    Lmao ob = new Lmao();
    Lmao.Inner wow = ob.new Inner();
    wow.hello();

    Lmao.Hello ob2 = new Lmao.Hello();
    ob2.lmao("WOAH");
  }
}
