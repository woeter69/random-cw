import java.util.Scanner;

public class FactorialStd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int result = 1;
        if (num > 1) {
            for (int i = num; i > 1; i--) {
                result = result * i;
            }
        }
        System.out.println(result);
    }
}
