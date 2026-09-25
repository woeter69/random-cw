import java.util.Scanner;

public class Shift {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println();
            System.out.println("Shift Operations Menu");
            System.out.println("1. Left Shift");
            System.out.println("2. Right Shift");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter number: ");
                    int numLeft = scanner.nextInt();
                    System.out.print("Enter number of shifts: ");
                    int shiftLeft = scanner.nextInt();
                    int resLeft = numLeft << shiftLeft;
                    System.out.println("Result: " + resLeft);
                    break;

                case 2:
                    System.out.print("Enter number: ");
                    int numRight = scanner.nextInt();
                    System.out.print("Enter number of shifts: ");
                    int shiftRight = scanner.nextInt();
                    int resRight = numRight >> shiftRight;
                    System.out.println("Result: " + resRight);
                    break;

                case 3:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 3);
    }
}
