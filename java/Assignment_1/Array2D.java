import java.util.Scanner;

public class Array2D {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter size of row: ");
    int size1 = scanner.nextInt();
    System.out.print("Enter size of column: ");
    int size2 = scanner.nextInt();
    int matrix[][] = new int[size1][size2];

    for (int i = 0; i < size1; i++) {
      for (int j = 0; j < size2; j++) {
        System.out.print("Enter value for index " + i + " " + j +" :");
        matrix[i][j] = scanner.nextInt();
      }
    }
    
    for (int i = 0; i < size1; i++) {
      for (int j = 0; j < size2; j++) {
        System.out.println("Matrix index " + i + " "+ j + " value " + matrix[i][j]); 
      }
    }
  }
}
