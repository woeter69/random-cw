import java.util.Scanner;

class Fibonacci { 
    static int fib(int n) {
        if (n <= 1) {
            return n;
        }
        return (fib(n - 1) + fib(n - 2));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of terms: ");
        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.print(fib(i) + " ");
        }
        
        scanner.close();
    }
}
