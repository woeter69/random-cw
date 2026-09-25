#include <iostream>
using namespace std;

void addMatrices(int a[10][10], int b[10][10], int res[10][10], int r, int c) {
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            res[i][j] = a[i][j] + b[i][j];
}

int main() {
    int a[10][10], b[10][10], res[10][10], r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;
    cout << "Enter elements of matrix 1:\n";
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            cin >> a[i][j];
    cout << "Enter elements of matrix 2:\n";
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            cin >> b[i][j];
    addMatrices(a, b, res, r, c);
    cout << "Sum:\n";
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
