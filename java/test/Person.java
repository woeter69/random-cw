import java.util.Scanner;

public class Person {
  String name;
  int age;

  Person(String name, int age) {
    this.age = age;
    this.name = name;
  }
}

public class Employee extends Person {
  int empId;
  Employee(String name, int age, int empId) {
    super(name,age);
    this.empId = empId;
  }
}

interface Shape {
  public int getArea();
};

public class Circle implements Shape {
  double radius;
  Circle(double radius) {
    this.radius = radius;
  }

  public double getArea() {
    return Math.PI * radius * radius;
  }
}
