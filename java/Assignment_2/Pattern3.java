import java.util.Scanner;

public class Pattern3 {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of rows: ");
        int rows = scanner.nextInt();

        for (int i = 1; i <= rows; i++) {
            int num;
            if (i % 2 != 0) {
              num = 1;
            }
            else {
              num = 2;
            }
              
            for (int j = 1; j <= i; j++) {
                System.out.print(num + " ");
                num += 2;
            }
            
            System.out.println();
        }
    }
}
