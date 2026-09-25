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
