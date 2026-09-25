import java.util.Scanner;

public class decimalToBinary {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter number to convert to binary: ");
    int decimal = scanner.nextInt();
    int temp = decimal;
    String temp_binary = "";
    
    if (decimal == 0) {
      temp_binary = "0";
    }
    else {
      while (decimal > 0) {
        int rem = decimal % 2;
        temp_binary += rem;
        decimal/=2;
      }

      int binary = Integer.parseInt(new StringBuilder(temp_binary).reverse().toString());
      System.out.println("Binary Conversion of " + temp + " is " + binary);
    }
  }
}