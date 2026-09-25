

import java.util.Scanner;

class Animal {
    void walk() { 
      System.out.println("I am walking"); 
    }
}

class Bird extends Animal {
    void fly() { 
      System.out.println("I am flying"); 
    }
}

class Shape {
    double getArea() { 
      return 0; 
    }
}

class Rectangle extends Shape {
    double width, length;
    Rectangle(double width, double length) {
        this.width = width;
        this.length = length;
    }
    @Override
    double getArea() { return width * length; }
}

class Circle extends Shape {
    double radius;
    Circle(double radius) { 
      this.radius = radius; 
    }
    @Override
    double getArea() { 
      return Math.PI * radius * radius; 
    }
}

class Person {
    String name;
    int age;
    Person(String name, int age) {
        this.name = name;
        this.age = age;
        System.out.println("Person constructor called");
    }
}

class StaffMember extends Person {
    int employeeId;
    StaffMember(String name, int age, int employeeId) {
        super(name, age);
        this.employeeId = employeeId;
        System.out.println("StaffMember constructor called");
    }
    void displayDetails() {
        System.out.println("ID: " + employeeId + " | Name: " + name + " | Age: " + age);
    }
}

class Employee {
    String name;
    double baseSalary;

    Employee(String name, double baseSalary) {
        this.name = name;
        this.baseSalary = baseSalary;
    }

    double getSalary() {
        return baseSalary;
    }
}

class Manager extends Employee {
    double bonus;

    Manager(String name, double baseSalary, double bonus) {
        super(name, baseSalary);
        this.bonus = bonus;
    }

    @Override
    double getSalary() {
        return super.getSalary() + bonus;
    }
}

class Developer extends Employee {
    int projectsCompleted;

    Developer(String name, double baseSalary, int projects) {
        super(name, baseSalary);
        this.projectsCompleted = projects;
    }

    @Override
    double getSalary() {
        return super.getSalary() + (projectsCompleted * 500);
    }
}

public class Assignment_3_162521 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n===== MENU =====");
            System.out.println("1. Basic Inheritance (Bird)");
            System.out.println("2. Method Overriding (Shapes)");
            System.out.println("3. Use of super Keyword (Staff)");
            System.out.println("4. Management System (Payrolls)");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    Bird eagle = new Bird();
                    eagle.walk();
                    eagle.fly();
                    break;

                case 2:
                    System.out.println("1. Rectangle\n2. Circle");
                    int choice_shape = scanner.nextInt();
                    if (choice_shape == 1) {
                        System.out.print("Width: "); double w = scanner.nextDouble();
                        System.out.print("Length: "); double l = scanner.nextDouble();
                        System.out.println("Area: " + new Rectangle(w, l).getArea());
                    } else {
                        System.out.print("Radius: "); double r = scanner.nextDouble();
                        System.out.println("Area: " + new Circle(r).getArea());
                    }
                    break;

                case 3:
                    StaffMember sm = new StaffMember("Chandragupt", 30, 101);
                    sm.displayDetails();
                    break;

                case 4:
                  System.out.print("Enter the number of employees: ");
                  int numEmployees = scanner.nextInt();
                  scanner.nextLine();

                  Employee[] staff = new Employee[numEmployees];

                  for (int i = 0; i < numEmployees; i++) {
                    System.out.println("\n--- Entry for Employee #" + (i + 1) + " ---");
                    System.out.print("Select Type (1: Manager, 2: Developer, 3: Regular): ");
                    int type = scanner.nextInt();
                    scanner.nextLine();

                    System.out.print("Enter Name: ");
                    String name = scanner.nextLine();
        
                    System.out.print("Enter Base Salary: ");
                    double baseSalary = scanner.nextDouble();

                    switch (type) {
                      case 1:
                        System.out.print("Enter Management Bonus: ");
                        double bonus = scanner.nextDouble();
                        staff[i] = new Manager(name, baseSalary, bonus);
                        break;
                      case 2:
                        System.out.print("Enter Number of Projects: ");
                        int projects = scanner.nextInt();
                        staff[i] = new Developer(name, baseSalary, projects);
                        break;
                      case 3:
                      default:
                        staff[i] = new Employee(name, baseSalary);
                        break;
                    }
                  }

                  System.out.println("\n--- Final Payroll Report ---");
                  for (Employee e : staff) {
                  System.out.println(e.name + ": $" + String.format("%.2f", e.getSalary()));
                }
                break;

                case 0:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid Choice...");
            }
        } while (choice != 0);
        scanner.close();
    }
}
