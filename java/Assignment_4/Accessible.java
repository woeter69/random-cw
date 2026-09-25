import packageA.*;
import packageB.*;

public class Accessible {
    public static void main(String[] args) {
        // BaseClass demonstration
        BaseClass bc = new BaseClass();
        bc.display();
        System.out.println();

        // Same Package Subclass demonstration
        SamePackageSubClass sps = new SamePackageSubClass();
        sps.display();
        System.out.println();

        // Same Package Non-Subclass demonstration
        SamePackageNonSubClass spns = new SamePackageNonSubClass();
        spns.display();
        System.out.println();

        // Different Package Subclass demonstration
        DifferentPackageSubClass dps = new DifferentPackageSubClass();
        dps.display();
        System.out.println();

        // Different Package Non-Subclass demonstration
        DifferentPackageNonSubClass dpns = new DifferentPackageNonSubClass();
        dpns.display();
    }
}
