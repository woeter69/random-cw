import java.util.Scanner;

public class Addition {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter amount of numbers: ");
    int num = scanner.nextInt();
    int temp;
    int result = 0;
    for (int i = 1; i <= num; i++) {
      System.out.print("Enter the " + i + " number: ");
      temp = scanner.nextInt();
      result+=temp;
    }
    System.out.println("Addition = " + result);
  }
}