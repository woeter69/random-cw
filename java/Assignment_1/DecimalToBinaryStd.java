import java.util.Scanner;

public class DecimalToBinaryStd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int decimal = scanner.nextInt();
        if (decimal == 0) {
            System.out.println("0");
        } else {
            String temp_binary = "";
            while (decimal > 0) {
                int rem = decimal % 2;
                temp_binary = rem + temp_binary;
                decimal /= 2;
            }
            System.out.println(temp_binary);
        }
    }
}
