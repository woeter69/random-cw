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
