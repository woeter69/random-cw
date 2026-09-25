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
