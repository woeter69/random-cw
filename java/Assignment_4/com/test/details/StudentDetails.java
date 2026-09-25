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
