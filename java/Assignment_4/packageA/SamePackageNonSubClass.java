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
