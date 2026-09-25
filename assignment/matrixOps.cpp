/**
 * @file matrixOps.cpp
 * @brief Performs various matrix operations (addition, multiplication, transpose)
 * 
 * This program provides functionality for basic matrix operations including
 * addition, multiplication, and transpose. It supports matrices up to 20x20.
 */

#include <iostream>

using namespace std;

/**
 * @brief Reads matrix elements from user input
 * 
 * Prompts the user to enter each element of the matrix row by row.
 * 
 * @param matrix 2D array to store the matrix elements
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 */
void inputMatrix(int matrix[20][20], int rows, int cols) {
    cout << "Enter elements of the matrix (" << rows << "x" << cols << "):\n";
    // Read each element of the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element for position (" << i << "," << j << "): ";
            cin >> matrix[i][j];
        }
    }
}

/**
 * @brief Displays a matrix to the console
 * 
 * Prints the matrix in a formatted grid layout.
 * 
 * @param matrix 2D array containing the matrix elements
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 */
void displayMatrix(int matrix[20][20], int rows, int cols) {
    cout << "Result Matrix:\n";
    // Display each row of the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * @brief Adds two matrices element-wise
 * 
 * Performs matrix addition by adding corresponding elements from matrices a and b.
 * Both matrices must have the same dimensions.
 * 
 * @param a First input matrix
 * @param b Second input matrix
 * @param result Output matrix to store the sum
 * @param rows Number of rows in the matrices
 * @param cols Number of columns in the matrices
 */
void addMatrix(int a[20][20], int b[20][20], int result[20][20], int rows, int cols) {
    // Add corresponding elements from both matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

/**
 * @brief Computes the transpose of a matrix
 * 
 * Creates a new matrix where rows and columns are swapped. The element at
 * position (i,j) in the original matrix becomes element (j,i) in the result.
 * 
 * @param matrix Input matrix to transpose
 * @param result Output matrix to store the transpose
 * @param rows Number of rows in the input matrix
 * @param cols Number of columns in the input matrix
 */
void transposeMatrix(int matrix[20][20], int result[20][20], int rows, int cols) {
    // Swap rows and columns
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

/**
 * @brief Multiplies two matrices
 * 
 * Performs matrix multiplication using the standard algorithm. For matrices
 * to be multipliable, the number of columns in the first matrix must equal
 * the number of rows in the second matrix.
 * 
 * @param a First input matrix (r1 x c1)
 * @param b Second input matrix (r2 x c2)
 * @param result Output matrix to store the product (r1 x c2)
 * @param r1 Number of rows in first matrix
 * @param c1 Number of columns in first matrix
 * @param r2 Number of rows in second matrix
 * @param c2 Number of columns in second matrix
 */
void multMatrix(int a[20][20], int b[20][20], int result[20][20], int r1, int c1, int r2, int c2) {
    // Check if matrices can be multiplied
    if (c1 != r2) {
        cout << "Invalid matrix for Multiplication";
    }
    else {
        // Multiply matrices using standard algorithm
        for (int i = 0; i < r1; i++) {
          for (int j = 0; j < c2; j++) {
              result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
              result[i][j] += a[i][k] * b[k][j];
            }
          }
        }
    }
}

/**
 * @brief Main function to perform matrix operations
 * 
 * Reads two matrices from user input and performs one of three operations:
 * addition, multiplication, or transpose based on user choice.
 * 
 * @return 0 on successful execution
 */
int main() {
    int r1, c1, r2, c2;  // Dimensions of matrices
    int matrix1[20][20], matrix2[20][20], result[20][20];  // Matrix storage
    int choice;  // User's operation choice

    // Read first matrix
    cout << "Enter rows and columns of Matrix 1:\n";
    cin >> r1 >> c1;
    inputMatrix(matrix1, r1, c1);

    // Read second matrix
    cout << "Enter rows and columns of Matrix 2:\n";
    cin >> r2 >> c2;
    inputMatrix(matrix2, r2, c2);

    // Get user's choice of operation
    cout << "\nChoose operation:\n1. Addition\n2. Multiplication\n3. Transpose of Matrix\n";
    cin >> choice;
    
    // Perform selected operation
    switch (choice) {
        case 1:  // Matrix Addition
            if (r1 == r2 && c1 == c2) {
              addMatrix(matrix1, matrix2, result, r1, c1);
              displayMatrix(result, r1, c1);
            } 
            else {
              cout << "Error: Matrices must have the same dimensions for addition.\n";
            }
            break;

        case 2:  // Matrix Multiplication
          multMatrix(matrix1, matrix2, result, r1, c1, r2, c2);
          displayMatrix(result, r1, c2);  
          break;

        case 3:  // Matrix Transpose
          transposeMatrix(matrix1, result, r1, c1);
          displayMatrix(result, c1, r1);
          break;

        default:
          cout << "Invalid Choice\n";
        }

    return 0;
}



