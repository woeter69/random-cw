package myInstitute;

public class Department {
    public void displayStaffDetails() {
        Staff staff = new Staff(101, "Alice", 75000);
        System.out.println("Displaying staff details from Department class:");
        staff.showStaffDetails();
    }
}
