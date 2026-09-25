public class objParameter {
  public static class Greeting {
    String name;
    Greeting(String name) {
      this.name = name;
    }

    public void Greet(Greeting person) {
      System.out.println("Hello, " + person.name);
    }

  }
  public static void main(String[] args) {
    Greeting person1 = new Greeting("Aditya");
    Greeting person2 = new Greeting("Pranjul");

    person1.Greet(person2);
  }
}
