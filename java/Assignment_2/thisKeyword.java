public class thisKeyword {
  String name;
  thisKeyword(String name) {
    this.name = name;
  }

  public void Greet() {
    System.out.println("Hello!" + name);
  }

  public static void main(String[] args) {
    thisKeyword hello = new thisKeyword("Aditya");

    System.out.println(hello.name);
    hello.Greet();
  }
}

/*
 * this keyword only persist till the object is alive 
 * It basically mean the object that was just passed with a value take that value to do something with it.
 * /
