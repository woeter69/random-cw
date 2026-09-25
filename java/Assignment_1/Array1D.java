import java.util.Scanner;

public class Array1D {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter size of array: ");
    int size = scanner.nextInt();

    int arr[] = new int[size];

    for (int i = 0; i < size; i++) {
      System.out.print("Enter value for element " + i + " ");
      arr[i] = scanner.nextInt();
    }
    
    for (int i = 0; i < size; i++) {
      System.out.println("Array index " + i + " value " + arr[i]);
    }
  }
}