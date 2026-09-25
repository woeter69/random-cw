#include <iostream>
using namespace std;

void multiplyMatrices(int a[10][10], int b[10][10], int res[10][10], int r1, int c1, int r2, int c2) {
    for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c2; ++j) {
            res[i][j] = 0;
            for(int k = 0; k < c1; ++k)
                res[i][j] += a[i][k] * b[k][j];
        }
}

int main() {
    int a[10][10], b[10][10], res[10][10], r1, c1, r2, c2;
    cout << "Enter rows and columns for matrix 1: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for matrix 2: ";
    cin >> r2 >> c2;
    if(c1 != r2) {
        cout << "Multiplication not possible!";
        return 0;
    }
    cout << "Enter matrix 1 elements:\n";
    for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c1; ++j)
            cin >> a[i][j];
    cout << "Enter matrix 2 elements:\n";
    for(int i = 0; i < r2; ++i)
        for(int j = 0; j < c2; ++j)
            cin >> b[i][j];
    multiplyMatrices(a, b, res, r1, c1, r2, c2);
    cout << "Product:\n";
    for(int i = 0; i < r1; ++i) {
        for(int j = 0; j < c2; ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
