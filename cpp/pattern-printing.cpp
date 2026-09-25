#include <iostream>
using namespace std;

// Changed to void because we don't need to return a value
void printSquare(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printEquilateralTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        // Spaces
        for (int j = n; j > i; j--) {
            cout << " ";
        }
        // Stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }
}

void ReverseTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printReversePyramid(int n) {
    for (int i = n; i >= 1; i--) {
        // Spaces
        for (int j = n; j > i; j--) {
            cout << " ";
        }
        // Stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        } 
        cout << endl;
    }
}

// --- THIS WAS THE BROKEN FUNCTION ---
// Fixed Logic: 
// 1. Loop i from n down to 1
// 2. Print (n - i) spaces
// 3. Print i stars
void rightReverseTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        
        // Step 1: Print Spaces
        // If n=5, i=5, spaces=0. If i=4, spaces=1.
        for (int j = 0; j < (n - i); j++) {
            cout << " ";
        }
        
        // Step 2: Print Stars
        // If i=5, print 5 stars.
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows for the pattern: ";
    cin >> n;

    cout << "\nSquare pattern:" << endl;
    printSquare(n);
    
    cout << "\nTriangle pattern:" << endl;
    printTriangle(n);
    
    cout << "\nEquilateral triangle pattern: " << endl;
    printEquilateralTriangle(n);
    
    cout << "\nReverse Pyramid: " << endl;
    printReversePyramid(n);
    
    cout << "\nReverse Triangle: " << endl;
    ReverseTriangle(n);
    
    cout << "\nRight Reverse Triangle: " << endl;
    rightReverseTriangle(n); // Now works correctly!

    return 0;
}
