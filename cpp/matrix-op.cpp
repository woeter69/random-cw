#include <iostream>
using namespace std;

//Function to make the matrices
void inputMatrix(int matrix[20][20], int rows, int cols) {
    cout << "Enter elements of the matrix (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element for position (" << i << "," << j << "): ";
            cin >> matrix[i][j];
        }
    }
}

//Function to Display the Matrix
void displayMatrix(int matrix[20][20], int rows, int cols) {
    cout << "Result Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//Function to add 2 matrices
bool addMatrix(int a[20][20], int b[20][20], int result[20][20], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return true;
}

//Function to subtract 2 matrices
bool subMatrix(int a[20][20], int b[20][20], int result[20][20], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return true;
}

//Function to Transpose a Matrix
void transposeMatrix(int matrix[20][20], int result[20][20], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

//Function to multiply 2 matrices
bool multMatrix(int a[20][20], int b[20][20], int result[20][20], int r1, int c1, int r2, int c2) {
    if (c1 != r2) return false;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return true;
}

int main() {
    int r1, c1, r2, c2;
    int matrix1[20][20], matrix2[20][20], result[20][20];
    int choice;

    cout << "Enter rows and columns of Matrix 1:\n";
    cin >> r1 >> c1;
    inputMatrix(matrix1, r1, c1);

    cout << "Enter rows and columns of Matrix 2:\n";
    cin >> r2 >> c2;
    inputMatrix(matrix2, r2, c2);

    cout << "\nChoose operation:\n1. Addition\n2. Multiplication\n3. Transpose of Matrix\n";
    cin >> choice;

    switch (choice) {
        case 1:
            if (r1 == r2 && c1 == c2) {
                addMatrix(matrix1, matrix2, result, r1, c1);
                displayMatrix(result, r1, c1);
            } else {
                cout << "Error: Matrices must have the same dimensions for addition.\n";
            }
            break;

        case 2:
            if (r1 == r2 && c1 == c2) {
                subMatrix(matrix1, matrix2, result, r1, c1);
                displayMatrix(result, r1, c1);
            } else {
                cout << "Error: Matrices must have the same dimensions for subtraction.\n";
            }
            break;

        case 3:
            if (multMatrix(matrix1, matrix2, result, r1, c1, r2, c2)) {
                displayMatrix(result, r1, c2);
            } else {
                cout << "Error: Multiplication not possible due to dimension mismatch.\n";
            }
            break;

        case 4:
            transposeMatrix(matrix1, result, r1, c1);
            displayMatrix(result, c1, r1); // note swapped rows & cols
            break;

        default:
            cout << "Invalid Choice\n";
    }

    return 0;
}
