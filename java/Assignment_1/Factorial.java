import java.util.Scanner;

public class Factorial {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter a number to find factorial: ");
    int num = scanner.nextInt();
    
    int result = 1;
    
    if (num == 0 || num == 1) {
      System.out.println("Factorial = " + result);
    }
    else {
      for (int i = num; i > 1; i--) {
        result = result * i; 
      }

      System.out.println("Factorial = " + result);
    }
  }
}