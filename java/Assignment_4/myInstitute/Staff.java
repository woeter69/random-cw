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
