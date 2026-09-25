import java.util.Scanner;

interface Shape {
    double calculateArea();
}

class Circle implements Shape {
    private double radius;
    public Circle(double radius) {
        this.radius = radius;
    }
    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle implements Shape {
    private double length, width;
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    @Override
    public double calculateArea() {
        return length * width;
    }
}

class Triangle implements Shape {
    private double base, height;
    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }
    @Override
    public double calculateArea() {
        return 0.5 * base * height;
    }
}

interface AdvancedArithmetic {
    int divisorSum(int n);
}

class MyCalculator implements AdvancedArithmetic {
    @Override
    public int divisorSum(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }
        return sum;
    }
}

interface Animal {
    void eat();
    void move();
}

class Dog implements Animal {
    @Override
    public void eat() {
        System.out.println("Dog eats bones.");
    }
    @Override
    public void move() {
        System.out.println("Dog runs on four legs.");
    }
}

class Cat implements Animal {
    @Override
    public void eat() {
        System.out.println("Cat drinks milk.");
    }
    @Override
    public void move() {
        System.out.println("Cat jumps gracefully.");
    }
}

class Student {
    protected int rollNo;
    protected String name;
    public void setStudentDetails(int rollNo, String name) {
        this.rollNo = rollNo;
        this.name = name;
    }
    public void displayStudentDetails() {
        System.out.println("Roll No: " + rollNo + "\nName: " + name);
    }
}

interface Sports {
    float SPORTS_MARKS = 50.0f;
    void displaySportsMarks();
}

class Result extends Student implements Sports {
    private float academicMarks;
    public void setAcademicMarks(float marks) {
        this.academicMarks = marks;
    }
    @Override
    public void displaySportsMarks() {
        System.out.println("Sports Marks: " + SPORTS_MARKS);
    }
    public void displayTotalResult() {
        displayStudentDetails();
        displaySportsMarks();
        System.out.println("Academic Marks: " + academicMarks);
        System.out.println("Total: " + (academicMarks + SPORTS_MARKS));
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Shape Area");
            System.out.println("2. Student Result (Multiple Inheritance)");
            System.out.println("3. Advanced Arithmetic (Divisor Sum)");
            System.out.println("4. Animal Behaviors");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("1. Circle\n2. Rectangle\n3. Triangle");
                    System.out.print("Enter choice: ");
                    int sChoice = scanner.nextInt();
                    if (sChoice == 1) {
                        System.out.print("Enter radius: ");
                        double r = scanner.nextDouble();
                        Circle circle = new Circle(r);
                        System.out.println("Area: " + circle.calculateArea());
                    } else if (sChoice == 2) {
                        System.out.print("Enter length and width: ");
                        double l = scanner.nextDouble();
                        double w = scanner.nextDouble();
                        Rectangle rectangle = new Rectangle(l, w);
                        System.out.println("Area: " + rectangle.calculateArea());
                    } else if (sChoice == 3) {
                        System.out.print("Enter base and height: ");
                        double b = scanner.nextDouble();
                        double h = scanner.nextDouble();
                        Triangle triangle = new Triangle(b, h);
                        System.out.println("Area: " + triangle.calculateArea());
                    }
                    break;
                case 2:
                    Result result = new Result();
                    System.out.print("Enter Roll No: ");
                    int roll = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Enter Name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter Academic Marks: ");
                    float marks = scanner.nextFloat();
                    result.setStudentDetails(roll, name);
                    result.setAcademicMarks(marks);
                    result.displayTotalResult();
                    break;
                case 3:
                    System.out.print("Enter integer: ");
                    int num = scanner.nextInt();
                    MyCalculator calculator = new MyCalculator();
                    System.out.println("Sum of divisors: " + calculator.divisorSum(num));
                    break;
                case 4:
                    System.out.println("1. Dog\n2. Cat");
                    System.out.print("Enter choice: ");
                    int aChoice = scanner.nextInt();
                    Animal animal;
                    if (aChoice == 1) {
                        animal = new Dog();
                    } else {
                        animal = new Cat();
                    }
                    animal.eat();
                    animal.move();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        } while (choice != 5);
        scanner.close();
    }
}
