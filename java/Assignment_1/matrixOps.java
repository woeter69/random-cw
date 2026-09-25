import java.util.Scanner;

public class matrixOps {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int choice;

        do {
            System.out.println();
            System.out.println("Matrix Operations");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter number of rows: ");
                    int rowsAdd = input.nextInt();
                    System.out.print("Enter number of columns: ");
                    int colsAdd = input.nextInt();

                    int[][] matAdd1 = new int[rowsAdd][colsAdd];
                    int[][] matAdd2 = new int[rowsAdd][colsAdd];
                    int[][] resAdd = new int[rowsAdd][colsAdd];

                    System.out.println("Enter elements of first matrix:");
                    for (int i = 0; i < rowsAdd; i++) {
                        for (int j = 0; j < colsAdd; j++) {
                            System.out.print("Enter value for " + (i + 1) + " " + (j + 1) + ": ");
                            matAdd1[i][j] = input.nextInt();
                        }
                    }

                    System.out.println("Enter elements of second matrix:");
                    for (int i = 0; i < rowsAdd; i++) {
                        for (int j = 0; j < colsAdd; j++) {
                            System.out.print("Enter value for " + (i + 1) + " " + (j + 1) + ": ");
                            matAdd2[i][j] = input.nextInt();
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

                case 2:
                    System.out.print("Enter number of rows: ");
                    int rowsSub = input.nextInt();
                    System.out.print("Enter number of columns: ");
                    int colsSub = input.nextInt();

                    int[][] matSub1 = new int[rowsSub][colsSub];
                    int[][] matSub2 = new int[rowsSub][colsSub];
                    int[][] resSub = new int[rowsSub][colsSub];

                    System.out.println("Enter elements of first matrix:");
                    for (int i = 0; i < rowsSub; i++) {
                        for (int j = 0; j < colsSub; j++) {
                            System.out.print("Enter value for " + (i + 1) + " " + (j + 1) + ": ");
                            matSub1[i][j] = input.nextInt();
                        }
                    }

                    System.out.println("Enter elements of second matrix:");
                    for (int i = 0; i < rowsSub; i++) {
                        for (int j = 0; j < colsSub; j++) {
                            System.out.print("Enter value for " + (i + 1) + " " + (j + 1) + ": ");
                            matSub2[i][j] = input.nextInt();
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

                case 3:
                    System.out.print("Enter rows for first matrix: ");
                    int r1 = input.nextInt();
                    System.out.print("Enter columns for first matrix: ");
                    int c1 = input.nextInt();

                    System.out.print("Enter rows for second matrix: ");
                    int r2 = input.nextInt();
                    System.out.print("Enter columns for second matrix: ");
                    int c2 = input.nextInt();

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
                                m1[i][j] = input.nextInt();
                            }
                        }

                        System.out.println("Enter elements of second matrix:");
                        for (int i = 0; i < r2; i++) {
                            for (int j = 0; j < c2; j++) {
                                System.out.print("Enter value for " + (i + 1) + " " + (j + 1) + ": ");
                                m2[i][j] = input.nextInt();
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

                case 4:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 4);
    }
}
