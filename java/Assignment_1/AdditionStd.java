import java.util.Scanner;

public class AdditionStd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int result = 0;
        for (int i = 0; i < num; i++) {
            result += scanner.nextInt();
        }
        System.out.println(result);
    }
}
