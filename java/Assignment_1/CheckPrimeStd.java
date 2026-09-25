import java.util.Scanner;

public class CheckPrimeStd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        boolean isPrime = true;
        if (num <= 1) {
            isPrime = false;
        } else {
            for (int i = 2; i < num; i++) {
                if ((num % i) == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            System.out.println("Yes " + num + " is prime");
        } else {
            System.out.println("No " + num + " is not prime");
        }
    }
}
