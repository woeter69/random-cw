import java.util.Scanner;

class AdditionWorker implements Runnable {
    int[][] m1, m2, result;
    int size;

    public AdditionWorker(int[][] m1, int[][] m2, int[][] result, int size) {
        this.m1 = m1;
        this.m2 = m2;
        this.result = result;
        this.size = size;
    }

    @Override
    public void run() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = m1[i][j] + m2[i][j];
            }
        }
    }
}

class SubtractionWorker implements Runnable {
    int[][] m1, m2, result;
    int size;

    public SubtractionWorker(int[][] m1, int[][] m2, int[][] result, int size) {
        this.m1 = m1;
        this.m2 = m2;
        this.result = result;
        this.size = size;
    }

    @Override
    public void run() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = m1[i][j] - m2[i][j];
            }
        }
    }
}

class MultiplicationWorker implements Runnable {
    int[][] m1, m2, result;
    int size;

    public MultiplicationWorker(int[][] m1, int[][] m2, int[][] result, int size) {
        this.m1 = m1;
        this.m2 = m2;
        this.result = result;
        this.size = size;
    }

    @Override
    public void run() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    result[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
    }
}

public class matrixOps {
    private static void printMatrix(int[][] matrix, int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(matrix[i][j] + "\t");
            }
            System.out.println();
        }
        System.out.println();
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Threaded Matrix Operations");
        System.out.print("Enter the size (N) for NxN square matrices: ");
        int size = scanner.nextInt();

        int[][] mat1 = new int[size][size];
        int[][] mat2 = new int[size][size];
        
        int[][] resAdd = new int[size][size];
        int[][] resSub = new int[size][size];
        int[][] resMult = new int[size][size];

        System.out.println("\nEnter elements of FIRST matrix:");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print("Enter value for row " + (i + 1) + " col " + (j + 1) + ": ");
                mat1[i][j] = scanner.nextInt();
            }
        }

        System.out.println("\nEnter elements of SECOND matrix:");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print("Enter value for row " + (i + 1) + " col " + (j + 1) + ": ");
                mat2[i][j] = scanner.nextInt();
            }
        }

        AdditionWorker addTask = new AdditionWorker(mat1, mat2, resAdd, size);
        SubtractionWorker subTask = new SubtractionWorker(mat1, mat2, resSub, size);
        MultiplicationWorker multTask = new MultiplicationWorker(mat1, mat2, resMult, size);

        Thread t1 = new Thread(addTask);
        Thread t2 = new Thread(subTask);
        Thread t3 = new Thread(multTask);

        System.out.println("\nCalculating Addition, Subtraction, and Multiplication simultaneously...");
        t1.start();
        t2.start();
        t3.start();

        try {
            t1.join();
            t2.join();
            t3.join();
        } catch (InterruptedException e) {
            System.out.println("A thread was interrupted.");
        }

        System.out.println("\nAll operations complete!");
        
        System.out.println("Result of Addition:");
        printMatrix(resAdd, size);

        System.out.println("Result of Subtraction:");
        printMatrix(resSub, size);

        System.out.println("Result of Multiplication:");
        printMatrix(resMult, size);

        scanner.close();
    }

}
