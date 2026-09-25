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
