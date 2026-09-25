import java.util.Scanner;

public class Array2DStd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size1 = scanner.nextInt();
        int size2 = scanner.nextInt();
        int matrix[][] = new int[size1][size2];
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                System.out.println(matrix[i][j]);
            }
        }
    }
}
