import java.util.Scanner;
public class Fibonacci {
  static long fib(int n) {
    if (n<=1) {
      return n;
    }
    long result = fib(n-1) + fib(n-2);
    return result;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int num = scanner.nextInt();
    for (int i = 0; i < num; i++) {
      System.out.print(fib(i) + " ");
    }
    System.out.println();
  }
}
