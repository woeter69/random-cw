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
