import java.util.Scanner;

public class Assignment_1_162502 {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("\n--- MAIN MENU ---");
            System.out.println("1. Addition");
            System.out.println("2. 1D Array");
            System.out.println("3. 2D Array");
            System.out.println("4. Check Prime");
            System.out.println("5. Decimal to Binary");
            System.out.println("6. Factorial");
            System.out.println("7. Matrix Operations");
            System.out.println("8. Pattern 1");
            System.out.println("9. Pattern 2");
            System.out.println("10. Shift Operations");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1: addition(); break;
                case 2: array1D(); break;
                case 3: array2D(); break;
                case 4: checkPrime(); break;
                case 5: decimalToBinary(); break;
                case 6: factorial(); break;
                case 7: matrixOps(); break;
                case 8: pattern1(); break;
                case 9: pattern2(); break;
                case 10: shiftOps(); break;
                case 0: System.out.println("Exiting..."); break;
                default: System.out.println("Invalid choice!");
            }
        } while (choice != 0);
    }

    static void addition() {
        System.out.print("Enter amount of numbers: ");
        int num = scanner.nextInt();
        int temp;
        int result = 0;
        for (int i = 1; i <= num; i++) {
            System.out.print("Enter the " + i + " number: ");
            temp = scanner.nextInt();
            result += temp;
        }
        System.out.println("Addition = " + result);
    }

    static void array1D() {
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

    static void array2D() {
        System.out.print("Enter size of row: ");
        int size1 = scanner.nextInt();
        System.out.print("Enter size of column: ");
        int size2 = scanner.nextInt();
        int matrix[][] = new int[size1][size2];
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                System.out.print("Enter value for index " + i + " " + j + " :");
                matrix[i][j] = scanner.nextInt();
            }
        }
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                System.out.println("Matrix index " + i + " " + j + " value " + matrix[i][j]);
            }
        }
    }

    static boolean isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i < n; i++) {
            if ((n % i) == 0) return false;
        }
        return true;
    }

    static void checkPrime() {
        System.out.print("Enter number to check prime: ");
        int num = scanner.nextInt();
        if (isPrime(num)) System.out.println("Yes " + num + " is prime");
        else System.out.println("No " + num + " is not prime");
    }

    static void decimalToBinary() {
        System.out.print("Enter number to convert to binary: ");
        int decimal = scanner.nextInt();
        int temp = decimal;
        String temp_binary = "";
        if (decimal == 0) {
            temp_binary = "0";
            System.out.println("Binary Conversion of 0 is 0");
        } else {
            while (decimal > 0) {
                int rem = decimal % 2;
                temp_binary += rem;
                decimal /= 2;
            }
            int binary = Integer.parseInt(new StringBuilder(temp_binary).reverse().toString());
            System.out.println("Binary Conversion of " + temp + " is " + binary);
        }
    }

    static void factorial() {
        System.out.print("Enter a number to find factorial: ");
        int num = scanner.nextInt();
        int result = 1;
        if (num == 0 || num == 1) {
            System.out.println("Factorial = " + result);
        } else {
            for (int i = num; i > 1; i--) {
                result = result * i;
            }
            System.out.println("Factorial = " + result);
        }
    }

    static void matrixOps() {
        int choice;
        do {
            System.out.println("\nMatrix Operations");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Return to Main Menu");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            switch (choice) {
                case 1: {
                    System.out.print("Enter number of rows: ");
                    int rowsAdd = scanner.nextInt();
                    System.out.print("Enter number of columns: ");
                    int colsAdd = scanner.nextInt();
                    int[][] matAdd1 = new int[rowsAdd][colsAdd];
                    int[][] matAdd2 = new int[rowsAdd][colsAdd];
                    int[][] resAdd = new int[rowsAdd][colsAdd];
                    System.out.println("Enter elements of first matrix:");
                    for (int i = 0; i < rowsAdd; i++) {
                        for (int j = 0; j < colsAdd; j++) {
                            System.out.print("Enter value for " + (i + 1) + " " + (j + 1) + ": ");
                            matAdd1[i][j] = scanner.nextInt();
                        }
                    }
                    System.out.println("Enter elements of second matrix:");
                    for (int i = 0; i < rowsAdd; i++) {
                        for (int j = 0; j < colsAdd; j++) {
                            System.out.print("Enter value for " + (i + 1) + " " + (j + 1) + ": ");
                            matAdd2[i][j] = scanner.nextInt();
                        }
                    }
                    for (int i = 0; i < rowsAdd; i++) {
                        for (int j = 0; j < colsAdd; j++) {
                            resAdd[i][j] = matAdd1[i][j] + matAdd2[i][j];
                        }
                    }
                    System.out.println("Result of Addition: ");
                    for (int i = 0; i < rowsAdd; i++) {
                        for (int j = 0; j < colsAdd; j++) {
                            System.out.print(resAdd[i][j] + " ");
                        }
                        System.out.println();
                    }
                    break;
                }
                case 2: {
                    System.out.print("Enter number of rows: ");
                    int rowsSub = scanner.nextInt();
                    System.out.print("Enter number of columns: ");
                    int colsSub = scanner.nextInt();
                    int[][] matSub1 = new int[rowsSub][colsSub];
                    int[][] matSub2 = new int[rowsSub][colsSub];
                    int[][] resSub = new int[rowsSub][colsSub];
                    System.out.println("Enter elements of first matrix:");
                    for (int i = 0; i < rowsSub; i++) {
                        for (int j = 0; j < colsSub; j++) {
                            System.out.print("Enter value for " + (i + 1) + " " + (j + 1) + ": ");
                            matSub1[i][j] = scanner.nextInt();
                        }
                    }
                    System.out.println("Enter elements of second matrix:");
                    for (int i = 0; i < rowsSub; i++) {
                        for (int j = 0; j < colsSub; j++) {
                            System.out.print("Enter value for " + (i + 1) + " " + (j + 1) + ": ");
                            matSub2[i][j] = scanner.nextInt();
                        }
                    }
                    for (int i = 0; i < rowsSub; i++) {
                        for (int j = 0; j < colsSub; j++) {
                            resSub[i][j] = matSub1[i][j] - matSub2[i][j];
                        }
                    }
                    System.out.println("Result of Subtraction: ");
                    for (int i = 0; i < rowsSub; i++) {
                        for (int j = 0; j < colsSub; j++) {
                            System.out.print(resSub[i][j] + " ");
                        }
                        System.out.println();
                    }
                    break;
                }
                case 3: {
                    System.out.print("Enter rows for first matrix: ");
                    int r1 = scanner.nextInt();
                    System.out.print("Enter columns for first matrix: ");
                    int c1 = scanner.nextInt();
                    System.out.print("Enter rows for second matrix: ");
                    int r2 = scanner.nextInt();
                    System.out.print("Enter columns for second matrix: ");
                    int c2 = scanner.nextInt();
                    if (c1 != r2) {
                        System.out.println("Matrix multiplication not possible. Cols of first must equal rows of second.");
                    } else {
                        int[][] m1 = new int[r1][c1];
                        int[][] m2 = new int[r2][c2];
                        int[][] product = new int[r1][c2];
                        System.out.println("Enter elements of first matrix:");
                        for (int i = 0; i < r1; i++) {
                            for (int j = 0; j < c1; j++) {
                                System.out.print("Enter value for " + (i + 1) + " " + (j + 1) + ": ");
                                m1[i][j] = scanner.nextInt();
                            }
                        }
                        System.out.println("Enter elements of second matrix:");
                        for (int i = 0; i < r2; i++) {
                            for (int j = 0; j < c2; j++) {
                                System.out.print("Enter value for " + (i + 1) + " " + (j + 1) + ": ");
                                m2[i][j] = scanner.nextInt();
                            }
                        }
                        for (int i = 0; i < r1; i++) {
                            for (int j = 0; j < c2; j++) {
                                for (int k = 0; k < c1; k++) {
                                    product[i][j] += m1[i][k] * m2[k][j];
                                }
                            }
                        }
                        System.out.println("Result of Multiplication:");
                        for (int i = 0; i < r1; i++) {
                            for (int j = 0; j < c2; j++) {
                                System.out.print(product[i][j] + " ");
                            }
                            System.out.println();
                        }
                    }
                    break;
                }
            }
        } while (choice != 4);
    }

    static void pattern1() {
        System.out.print("Enter number of rows: ");
        int rows = scanner.nextInt();
        for (int i = 1; i <= rows; i++) {
            for (int j = rows; j >= i; j--) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }

    static void pattern2() {
        System.out.print("Enter number of rows: ");
        int rows = scanner.nextInt();
        for (int i = rows; i > 0; i--) {
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    static void shiftOps() {
        int choice;
        do {
            System.out.println("\nShift Operations Menu");
            System.out.println("1. Left Shift");
            System.out.println("2. Right Shift");
            System.out.println("3. Return to Main Menu");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter number: ");
                    int numLeft = scanner.nextInt();
                    System.out.print("Enter number of shifts: ");
                    int shiftLeft = scanner.nextInt();
                    int resLeft = numLeft << shiftLeft;
                    System.out.println("Result: " + resLeft);
                    break;
                case 2:
                    System.out.print("Enter number: ");
                    int numRight = scanner.nextInt();
                    System.out.print("Enter number of shifts: ");
                    int shiftRight = scanner.nextInt();
                    int resRight = numRight >> shiftRight;
                    System.out.println("Result: " + resRight);
                    break;
            }
        } while (choice != 3);
    }
}
