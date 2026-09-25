import java.util.Scanner;

class Pattern2 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter number of rows: ");
    int rows = scanner.nextInt();
    for (int i = 1; i <= rows; i++) {
      for (int j = rows; j >= i; j--) {
        System.out.print("* ");
      }
      System.out.println();
    }
  }
}
