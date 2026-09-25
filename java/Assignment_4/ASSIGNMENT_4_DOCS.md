# Assignment 4: Packages and Interfaces

## Questions

### PACKAGE
1. **User-Defined Package Creation:** Write a program to create a user-defined package (e.g., mypack) containing a class and import it into another program.
2. **Package with Multiple Classes:** Develop a package named myInstitute that includes a class Department with a method to display staff details. Create a separate program to import and use this class.
3. **Access Modifiers in Packages:** Demonstrate the visibility of public, private, protected, and default members across different classes in the same package and in different packages.
4. **Sub-packages:** Create a nested package structure (e.g., com.test.details) and access its classes from a main application.
5. **Mathematical Operations Package:** Create a package containing classes for basic arithmetic (Add, Sub, Mul, Div) and import them into a calculator application.

### INTERFACE
1. **Shape Calculation:** Create a Shape interface with a method calculateArea(). Implement it in classes like Circle, Rectangle, and Triangle to demonstrate polymorphism.
2. **Multiple Inheritance:** Use interfaces to solve the diamond problem. For example, a Student class and a Sports interface both contribute to a final Result class.
3. **Advanced Arithmetic:** Implement an interface like AdvancedArithmetic with a method divisorSum(int n) that returns the sum of all divisors of a given integer.
4. **Animal Behaviors:** Define an Animal interface with eat() and move() methods. Create specific classes like Dog and Cat that implement these behaviors differently.

---

## Part 1: Packages

### File Structure
The project is organized into multiple directories, each representing a Java package:
```
Assignment_4/
├── Arithmetic/
│   ├── Add.java
│   ├── Div.java
│   ├── Mul.java
│   └── Sub.java
├── com/
│   └── test/
│       └── details/
│           └── StudentDetails.java
├── importClass/
│   └── importClass.java
├── myInstitute/
│   ├── Department.java
│   └── Staff.java
├── packageA/
│   ├── BaseClass.java
│   ├── SamePackageNonSubClass.java
│   └── SamePackageSubClass.java
├── packageB/
│   ├── DifferentPackageNonSubClass.java
│   └── DifferentPackageSubClass.java
└── MainApplication.java
```

### Connection and Logic
1. **MainApplication.java**: This is the central menu-driven program. It uses `import` statements to pull in classes from all the custom packages.
2. **Encapsulation**: Classes in `Arithmetic` provide specialized logic for math, keeping the main program clean.
3. **Access Control**: `packageA` and `packageB` are specifically designed to show how `protected` and `default` modifiers behave when crossing package boundaries.
4. **Sub-packages**: The `com.test.details` path demonstrates that Java treats nested folders as distinct sub-packages.
5. **myInstitute**: Demonstrates internal package collaboration, where `Department` uses the `Staff` class from the same package.

---

### Package Source Code

#### importClass/importClass.java
```java
package importClass;

public class importClass {
  public void hello() {
    System.out.println("Hello");
  }
}
```

#### myInstitute/Staff.java
```java
package myInstitute;

public class Staff {
  int empId = 0001;
  String name = "John";
  int salary = 5000;

  public Staff(int empId, String name, int salary) {
    this.empId = empId;
    this.name = name;
    this.salary = salary;
  }

  public void showStaffDetails() {
    System.out.println("Name: " + name);
    System.out.println("Employee Id: " + empId);
    System.out.println("Salary: " + salary);
  }
}
```

#### myInstitute/Department.java
```java
package myInstitute;

public class Department {
    public void displayStaffDetails() {
        Staff staff = new Staff(101, "Alice", 75000);
        System.out.println("Displaying staff details from Department class:");
        staff.showStaffDetails();
    }
}
```

#### packageA/BaseClass.java
```java
package packageA;

public class BaseClass {
    public String publicField = "Public: Accessible everywhere";
    protected String protectedField = "Protected: Same package and subclasses";
    String defaultField = "Default: Same package only";
    private String privateField = "Private: This class only";

    public void display() {
        System.out.println("Accessing from BaseClass (Same class):");
        System.out.println(publicField);
        System.out.println(protectedField);
        System.out.println(defaultField);
        System.out.println(privateField); // Accessible in same class
    }
}
```

#### packageA/SamePackageSubClass.java
```java
package packageA;

public class SamePackageSubClass extends BaseClass {
    public void display() {
        System.out.println("Accessing from SamePackageSubClass:");
        System.out.println(publicField);    // Accessible
        System.out.println(protectedField); // Accessible (subclass/same package)
        System.out.println(defaultField);   // Accessible (same package)
        // System.out.println(privateField); // Error: private is not accessible
    }
}
```

#### packageA/SamePackageNonSubClass.java
```java
package packageA;

public class SamePackageNonSubClass {
    public void display() {
        BaseClass bc = new BaseClass();
        System.out.println("Accessing from SamePackageNonSubClass:");
        System.out.println(bc.publicField);    // Accessible
        System.out.println(bc.protectedField); // Accessible (same package)
        System.out.println(bc.defaultField);   // Accessible (same package)
        // System.out.println(bc.privateField); // Error: private is not accessible
    }
}
```

#### packageB/DifferentPackageSubClass.java
```java
package packageB;

import packageA.BaseClass;

public class DifferentPackageSubClass extends BaseClass {
    public void display() {
        System.out.println("Accessing from DifferentPackageSubClass:");
        System.out.println(publicField);    // Accessible
        System.out.println(protectedField); // Accessible (via inheritance)
        // System.out.println(defaultField);   // Error: default not accessible in different package
        // System.out.println(privateField);   // Error: private not accessible
    }
}
```

#### packageB/DifferentPackageNonSubClass.java
```java
package packageB;

import packageA.BaseClass;

public class DifferentPackageNonSubClass {
    public void display() {
        BaseClass bc = new BaseClass();
        System.out.println("Accessing from DifferentPackageNonSubClass:");
        System.out.println(bc.publicField); // Accessible
        // System.out.println(bc.protectedField); // Error: protected not accessible to non-subclass in different package
        // System.out.println(bc.defaultField);   // Error: default not accessible in different package
        // System.out.println(bc.privateField);   // Error: private not accessible
    }
}
```

#### com/test/details/StudentDetails.java
```java
package com.test.details;

public class StudentDetails {
    private String name;
    private int rollNumber;

    public StudentDetails(String name, int rollNumber) {
        this.name = name;
        this.rollNumber = rollNumber;
    }

    public void displayInfo() {
        System.out.println("Accessing nested package: com.test.details");
        System.out.println("Student Name: " + name);
        System.out.println("Roll Number: " + rollNumber);
    }
}
```

#### Arithmetic/Add.java
```java
package Arithmetic;

public class Add {
    public double calculate(double a, double b) {
        return a + b;
    }
}
```

#### Arithmetic/Sub.java
```java
package Arithmetic;

public class Sub {
    public double calculate(double a, double b) {
        return a - b;
    }
}
```

#### Arithmetic/Mul.java
```java
package Arithmetic;

public class Mul {
    public double calculate(double a, double b) {
        return a * b;
    }
}
```

#### Arithmetic/Div.java
```java
package Arithmetic;

public class Div {
    public double calculate(double a, double b) {
        if (b == 0) {
            System.out.println("Error: Division by zero");
            return Double.NaN;
        }
        return a / b;
    }
}
```

#### MainApplication.java
```java
import java.util.Scanner;
import importClass.importClass;
import myInstitute.Department;
import packageA.*;
import packageB.*;
import com.test.details.StudentDetails;
import Arithmetic.*;

public class MainApplication {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\n--- PACKAGE ASSIGNMENT MENU ---");
            System.out.println("1. User-Defined Package (mypack/importClass)");
            System.out.println("2. Package with Multiple Classes (myInstitute)");
            System.out.println("3. Access Modifiers in Packages");
            System.out.println("4. Sub-packages (com.test.details)");
            System.out.println("5. Mathematical Operations Package (Arithmetic)");
            System.out.println("6. Exit");
            System.out.print("Enter choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    importClass obj = new importClass();
                    obj.hello();
                    break;
                case 2:
                    Department dept = new Department();
                    dept.displayStaffDetails();
                    break;
                case 3:
                    System.out.println("Demonstrating visibility across packages:");
                    BaseClass base = new BaseClass();
                    base.display();
                    
                    SamePackageSubClass sps = new SamePackageSubClass();
                    sps.display();
                    
                    SamePackageNonSubClass spns = new SamePackageNonSubClass();
                    spns.display();
                    
                    DifferentPackageSubClass dps = new DifferentPackageSubClass();
                    dps.display();
                    
                    DifferentPackageNonSubClass dpns = new DifferentPackageNonSubClass();
                    dpns.display();
                    break;
                case 4:
                    System.out.print("Enter Student Name: ");
                    scanner.nextLine();
                    String name = scanner.nextLine();
                    System.out.print("Enter Roll Number: ");
                    int roll = scanner.nextInt();
                    StudentDetails student = new StudentDetails(name, roll);
                    student.displayInfo();
                    break;
                case 5:
                    System.out.print("Enter first number: ");
                    double num1 = scanner.nextDouble();
                    System.out.print("Enter second number: ");
                    double num2 = scanner.nextDouble();
                    
                    Add add = new Add();
                    Sub sub = new Sub();
                    Mul mul = new Mul();
                    Div div = new Div();
                    
                    System.out.println("Addition: " + add.calculate(num1, num2));
                    System.out.println("Subtraction: " + sub.calculate(num1, num2));
                    System.out.println("Multiplication: " + mul.calculate(num1, num2));
                    System.out.println("Division: " + div.calculate(num1, num2));
                    break;
                case 6:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        } while (choice != 6);
        scanner.close();
    }
}
```

---

## Part 2: Interfaces

### Source Code (Interfaces/Main.java)

```java
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
```
