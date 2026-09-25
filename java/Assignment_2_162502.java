import java.util.Scanner;

class methodOverload {
    int length;
    int width;

    static int area() {
        int length = 10;
        int width = 10;
        return width * length;
    }

    static int area(int length, int width) {
        return length * width;
    }
}

class Overload {
    int healthpoint;
    int mana;
    int stamina;

    Overload() {
        healthpoint = 100;
        mana = 100;
        stamina = 200;
    }

    Overload(int hp, int fp, int stm) {
        healthpoint = hp;
        mana = fp;
        stamina = stm;
    }
}

class thisKeyword {
    String name;

    thisKeyword(String name) {
        this.name = name;
    }

    public void Greet() {
        System.out.println("Hello!" + name);
    }
}

class Greeting {
    String name;

    Greeting(String name) {
        this.name = name;
    }

    public void Greet(Greeting person) {
        System.out.println("Hello, " + person.name);
    }
}

class callByValue {
    public static void increment(int number) {
        number = number + 1;
    }
}

class callByReference {
    int value;

    callByReference(int val) {
        this.value = val;
    }

    public static void increment(callByReference c) {
        c.value = c.value + 1;
    }
}

class Fibonacci {
    static int fib(int n) {
        if (n <= 1) {
            return n;
        }
        return (fib(n - 1) + fib(n - 2));
    }
}

class Outer {
    String name;
    class Inner {
        void Shout(String name) {
            Outer.this.name = name;
            System.out.println(name.toUpperCase() + "!!!");
        }
    }
    static class StaticInner {
      void Hello(String name) {
        System.out.println("Hello " + name);
      } 
    }
}

public class Assignment_2_162502 {
    public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      int choice = -1;

      if (args.length > 0) {
        choice = Integer.parseInt(args[0]);
        
        if (choice < 0 || choice > 9) {
            System.out.println("Argument out of range (0-9). Loading menu...");
            choice = -1;
        }
      }

        do {
            if (choice == -1) {
              System.out.println("\n===== MENU =====");
              System.out.println("1. Method Overloading");
              System.out.println("2. Constructor Overloading");
              System.out.println("3. Use of this Keyword");
              System.out.println("4. Object Passed as Parameter");
              System.out.println("5. Call By Value");
              System.out.println("6. Call By Reference");
              System.out.println("7. Pattern");
              System.out.println("8. Fibonacci");
              System.out.println("9. Inner Classes");
              System.out.println("0. Exit");
              System.out.print("Enter your choice: ");
              choice = scanner.nextInt();
            }

            switch (choice) {
                case 1:
                    System.out.println("Method Overloading Output:");
                    System.out.println(methodOverload.area(10, 20));
                    System.out.println(methodOverload.area());
                    break;
                case 2:
                    Overload player1 = new Overload();
                    Overload player2 = new Overload(200, 200, 5);

                    System.out.println("Player 2 -> HP: " + player2.healthpoint + ", Mana: " + player2.mana + ", Stamina: " + player2.stamina);
                    break;
                case 3:
                    thisKeyword hello = new thisKeyword("Aditya");
                    hello.Greet();
                    break;
                case 4:
                    Greeting person1 = new Greeting("Aditya");
                    Greeting person2 = new Greeting("Pranjul");
                    person1.Greet(person2);
                    break;
                case 5:
                    int count = 10;
                    callByValue.increment(count);
                    System.out.println("Value after method (Call by Value): " + count);
                    break;
                case 6:
                    callByReference myCounter = new callByReference(10);
                    callByReference.increment(myCounter);
                    System.out.println("Value after method (Call by Reference): " + myCounter.value);
                    break;
                case 7:
                    System.out.print("Enter number of rows: ");
                    int rows = scanner.nextInt();
                    for (int i = 1; i <= rows; i++) {
                        int num = (i % 2 != 0) ? 1 : 2;
                        for (int j = 1; j <= i; j++) {
                            System.out.print(num + " ");
                            num += 2;
                        }
                        System.out.println();
                    }
                    break;
                case 8:
                    System.out.print("Enter the number of terms: ");
                    int n = scanner.nextInt();
                    for (int i = 0; i < n; i++) System.out.print(Fibonacci.fib(i) + " ");
                    System.out.println();
                    break;
                case 9:
                  System.out.println("1. Inner Class (Non Static)");
                  System.out.println("2. Inner Class (Static)");
                  System.out.print("Enter your choice: ");
                  int inner_choice = scanner.nextInt();
                  switch(inner_choice) {
                    case 1:
                      scanner.nextLine();
                      System.out.print("Enter name for shouting: ");
                      String shouter = scanner.nextLine();
                      Outer myOuter = new Outer();
                      Outer.Inner Mic = myOuter.new Inner();
                      Mic.Shout(shouter);
                      break;
                    case 2:
                      scanner.nextLine();
                      System.out.print("Enter name to say Hello: ");
                      String Name = scanner.nextLine();
                      Outer.StaticInner Person = new Outer.StaticInner();
                      Person.Hello(Name);   
                  }
                  break;
                case 0:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice.");
            }

            if (choice != 0) {
              choice = -1;
            }

        } while (choice != 0);

        scanner.close();
    }
}
